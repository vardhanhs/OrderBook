#include <iostream>
#include "order.h"
#include "order_book.h"
#include "trade.h"

int main() {
    OrderBook ob;

    ob.addOrder(Order(1, "BTC", 45000.0, 2, Order::BUY));  // Buy 2 BTC at $45,000
    ob.addOrder(Order(2, "BTC", 45010.0, 1, Order::SELL)); // Sell 1 BTC at $45,010
    ob.addOrder(Order(3, "ETH", 3500.0, 5, Order::BUY));   // Buy 5 ETH at $3500
    ob.addOrder(Order(4, "ETH", 3490.0, 2, Order::SELL));  // Sell 2 ETH at $3490
    ob.addOrder(Order(5, "BTC", 45010.0, 2, Order::BUY));  // Buy 2 BTC at $45,010
    ob.addOrder(Order(6, "ETH", 3500.0, 3, Order::SELL));  // Sell 3 ETH at $3500

    ob.printTrades();

    //(TODO) Fo testing, remove it in final version.
    std::cin.get();

    return 0;
}
