#include "order_book.h"

OrderBook::OrderBook(size_t numThreads) : pool(numThreads) {}



void OrderBook::addOrder(const Order& order) {
    const std::string& asset = order.getAsset();
    
    // Creating new asset if it is not present
    if (assetBooks.find(asset) == assetBooks.end()) {
        assetBooks[asset] = { BuyOrderQueue(), SellOrderQueue() };
        assetLocks[asset];  
    }

    std::lock_guard<std::mutex> lock(assetLocks[asset]);
    auto& buyOrders = assetBooks[asset].first;
    auto& sellOrders = assetBooks[asset].second;

    // Make a mutable copy of the order
    Order mutableOrder = order; // why making mutable copy ?

    if (order.getType() == Order::BUY) {
        processBuyOrder(mutableOrder, sellOrders);
    } else {
        processSellOrder(mutableOrder, buyOrders);
    }
}

void OrderBook::processBuyOrder(Order& incomingOrder, SellOrderQueue& sellOrders) {
    while (!sellOrders.empty()) {

        // Create a mutable copy of the top element
        Order matchingOrder = sellOrders.top(); // can we store pointers to objects and modify it.
        if (incomingOrder.getPrice() < matchingOrder.getPrice()) {
            break;
        }

        // Process trade
        int matchQty = std::min(incomingOrder.getQuantity(), matchingOrder.getQuantity());
        // (TODO) add order id of trades
        trades.emplace_back(incomingOrder.getAsset(), matchingOrder.getPrice(), matchQty, std::time(nullptr));
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
        auto& buyOrders = assetBooks[incomingOrder.getAsset()].first;
        buyOrders.push(incomingOrder);
    }
}

void OrderBook::processSellOrder(Order& incomingOrder, BuyOrderQueue& buyOrders) {
    while (!buyOrders.empty()) {
        
        // Create a mutable copy of the top element
        Order matchingOrder = buyOrders.top();
        if (incomingOrder.getPrice() > matchingOrder.getPrice()) {
            break;
        }

        // Process trade
        int matchQty = std::min(incomingOrder.getQuantity(), matchingOrder.getQuantity());
        // (TODO) add order id of trades
        trades.emplace_back(incomingOrder.getAsset(), matchingOrder.getPrice(), matchQty, std::time(nullptr));

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
        auto& sellOrders = assetBooks[incomingOrder.getAsset()].second;
        sellOrders.push(incomingOrder);
    }
}

void OrderBook::printTrades() const {
    for (const auto& trade : trades) {
        trade.printTrade();
    }
}
