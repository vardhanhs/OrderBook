#pragma once

#include <map>
#include <vector>
#include <string>
#include <queue>
#include <mutex>
#include "order.h"
#include "trade.h"
#include "thread_pool.h"

// Comparison functors
// If order have same prices then orders having earlier timestamp (placed before) is given priority
struct CompareBuyOrder {
    bool operator()(const Order& o1, const Order& o2) const {
        if (o1.getPrice() != o2.getPrice()) {
            return o1.getPrice() < o2.getPrice();
        }
        return o1.getTimestamp() > o2.getTimestamp();
    }
};

struct CompareSellOrder {
    bool operator()(const Order& o1, const Order& o2) const {
        if (o1.getPrice() != o2.getPrice()) {
            return o1.getPrice() > o2.getPrice();
        }
        return o1.getTimestamp() > o2.getTimestamp();
    }
};

/* Priority queue for buy and sell oeders.
Why priority queue over maps/ sets ?
Assuming that 90% of the orders placed are never processed, looking at the min/ max element 
in a heap is faster O(n) as compared to sets and maps.
*/
typedef std::priority_queue<Order, std::vector<Order>, CompareBuyOrder> BuyOrderQueue;
typedef std::priority_queue<Order, std::vector<Order>, CompareSellOrder> SellOrderQueue;

class OrderBook {
private:
    std::map<std::string, std::pair<BuyOrderQueue, SellOrderQueue>> assetBooks;

    /*Here if we do not keep this asset book and simply assign orders to different threads
     randomly then it will be a bit faster but there is a chance that some order which is 
     placed for a particular asset after a given order gets processed first. To ensure that
     orders in a given asset gets processed in FIFO manner we need to keep track of it. 
    */ 
    std::map<std::string, std::queue<Order>> assetOrderQueue;

    // mutex for each assetQueues
    std::map<std::string, std::mutex> assetQueueLocks;

    std::vector<Trade> trades;

    // To avoid race condition between multiple threads saving trades.
    std::mutex saveTrade;

    ThreadPool pool;

public:
    OrderBook(size_t numThreads);

    void addOrder(Order&& order);
    // (Note) Return all trades which are exceuted by worker threads upto that point of time.
    void getExecutedTrades() const;

private:
    void processOrderQueue(const std::string& asset);
    void processBuyOrder(Order& incomingOrder, const std::string& asset);
    void processSellOrder(Order& incomingOrder, const std::string& asset);
    
};

