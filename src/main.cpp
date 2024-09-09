#include <iostream>
#include <thread> 
#include <chrono>
#include "order.h"
#include "order_book.h"
#include "trade.h"

int main() {
    OrderBook ob(2);

    ob.addOrder(Order(1, "TATA", 4500.0, 2, Order::BUY));  // Buy 2 TATA at 4500
    ob.addOrder(Order(2, "TATA", 4510.0, 1, Order::SELL)); // Sell 1 TATA at 4510
    ob.addOrder(Order(3, "CERA", 350.0, 5, Order::BUY));   // Buy 5 CERA at 350
    ob.addOrder(Order(4, "CERA", 349.0, 2, Order::SELL));  // Sell 2 CERA at 349
    ob.addOrder(Order(5, "TATA", 4510.0, 2, Order::BUY));  // Buy 2 TATA at $4510
    ob.addOrder(Order(6, "CERA", 350.0, 3, Order::SELL));  // Sell 3 CERA at $350

    /* (Caution) print trades after worker threads finish execution of trades, otherwise it will be incorrect.
    For testing we are making main thread sleep for 1 sec so workers can finish trade.
    */
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::vector<Trade> trades = ob.getExecutedTrades();
    for (const auto& trade : trades) {
        trade.printTrade();
    }

    //(TODO) For testing, remove it in final version.
    std::cin.get();

    return 0;
}
