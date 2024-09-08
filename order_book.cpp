#include "order_book.h"

OrderBook::OrderBook(size_t numThreads) : pool(numThreads) {}

void OrderBook::addOrder(Order&& order) {
    const std::string& asset = order.getAsset();

    {   
        std::lock_guard<std::mutex> lock(assetQueueLocks[asset]);
        assetOrderQueue[asset].push(order);
    }

    // enque task
    pool.enqueueTask([this, asset]() {
        processOrderQueue(asset);
    });
    // std::cout<<"Order added"<<std::endl;
}

void OrderBook::processOrderQueue(const std::string& asset) {
    while (true) {

        if (assetOrderQueue[asset].empty()) {
                return;
        }

        std::lock_guard<std::mutex> lock(assetQueueLocks[asset]);

        Order order = assetOrderQueue[asset].front();
        assetOrderQueue[asset].pop();        

        if (order.getType() == Order::BUY) {
            processBuyOrder(order, asset);
        } else {
            processSellOrder(order, asset);
        }
    }
}

void OrderBook::processBuyOrder(Order& incomingOrder, const std::string& asset) {
    
    auto& buyOrders = assetBooks[asset].first;
    auto& sellOrders = assetBooks[asset].second;
    
    while (!sellOrders.empty()) {

        // Create a mutable copy of the top element
        Order matchingOrder = sellOrders.top(); // can we store pointers to objects and modify it.
        if (incomingOrder.getPrice() < matchingOrder.getPrice()) {
            break;
        }

        // Process trade
        int matchQty = std::min(incomingOrder.getQuantity(), matchingOrder.getQuantity());

        {
            std::lock_guard<std::mutex> lock(saveTrade);
            // (TODO) add order id of trades
            trades.emplace_back(incomingOrder.getAsset(), matchingOrder.getPrice(), matchQty, std::time(nullptr));
        }
        // Update quantities
        incomingOrder.reduceQuantity(matchQty);
        matchingOrder.reduceQuantity(matchQty);

        // (TODO) we can save time complexity of these extra push and pop functions id we can 
        // acess the matching order by it's reference.
        if (matchingOrder.getQuantity() == 0) {
            // Remove executed Order.
            sellOrders.pop();
        } else {
            // Insert modified matching order
            sellOrders.pop();
            if (matchingOrder.getQuantity() > 0) {
                sellOrders.push(matchingOrder);
            }
        }

        if (incomingOrder.getQuantity() == 0) {
            break;
        }
    }

    // Adding to buy order queue
    if (incomingOrder.getQuantity() > 0) {
        buyOrders.push(incomingOrder);
    }
}

void OrderBook::processSellOrder(Order& incomingOrder, const std::string& asset) {
    
    auto& buyOrders = assetBooks[asset].first;
    auto& sellOrders = assetBooks[asset].second;

    while (!buyOrders.empty()) {
        
        // Create a mutable copy of the top element
        Order matchingOrder = buyOrders.top();
        if (incomingOrder.getPrice() > matchingOrder.getPrice()) {
            break;
        }

        // Process trade
        int matchQty = std::min(incomingOrder.getQuantity(), matchingOrder.getQuantity());
        {
            std::lock_guard<std::mutex> lock(saveTrade);
            // (TODO) add order id of trades
            trades.emplace_back(incomingOrder.getAsset(), matchingOrder.getPrice(), matchQty, std::time(nullptr));
        }

        // Update quantities
        incomingOrder.reduceQuantity(matchQty);
        matchingOrder.reduceQuantity(matchQty);

        // (TODO) we can save time complexity of these extra push and pop functions id we can 
        // acess the matching order by it's reference.
        if (matchingOrder.getQuantity() == 0) {
            buyOrders.pop();
        } else {
            buyOrders.pop();
            if (matchingOrder.getQuantity() > 0) {
                buyOrders.push(matchingOrder);
            }
        }

        if (incomingOrder.getQuantity() == 0) {
            break;
        }
    }

    if (incomingOrder.getQuantity() > 0) {
        sellOrders.push(incomingOrder);
    }
}

void OrderBook::getExecutedTrades() const {
    for (const auto& trade : trades) {
        trade.printTrade();
    }
}
