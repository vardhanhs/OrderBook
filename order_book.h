#pragma once

#include <map>
#include <vector>
#include <string>
#include <queue>
#include "order.h"
#include "trade.h"

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

// Priority queue for buy and sell oeders.
// Why priority queue over maps/ sets ?
// Assuming that 90% of the orders placed are never processed, looking at the min/ max element 
// in a heap is faster O(n) as compared to sets and maps.
typedef std::priority_queue<Order, std::vector<Order>, CompareBuyOrder> BuyOrderQueue;
typedef std::priority_queue<Order, std::vector<Order>, CompareSellOrder> SellOrderQueue;

class OrderBook {
private:
    std::map<std::string, std::pair<BuyOrderQueue, SellOrderQueue>> assetBooks;
    std::vector<Trade> trades;

public:
    void addOrder(const Order& order);
    void printTrades() const;

private:
    void processBuyOrder(Order& incomingOrder, SellOrderQueue& sellOrders);
    void processSellOrder(Order& incomingOrder, BuyOrderQueue& buyOrders);
    
};

