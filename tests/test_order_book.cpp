#include <gtest/gtest.h>
#include "../src/order_book.h"

// This is wait time used in tests for workers to execute order
// before checking for trades.
#define wait_time 1

// No trade should occur when prices don't match
TEST(OrderBookTest, NoTradeDueToPriceMismatch) {

    OrderBook orderBook(2);

    orderBook.addOrder(Order (1, "AAPL", 150.0, 10, Order::BUY));
    orderBook.addOrder(Order (2, "AAPL", 155.0, 10, Order::SELL));

    // Wait for threads to process
    std::this_thread::sleep_for(std::chrono::seconds(wait_time));

    // No trades should be executed since prices don't match
    EXPECT_EQ(orderBook.getExecutedTrades().size(), 0);
}

// 1 trade should occur when quantity match
// Validating (Assumption#1) 
TEST(OrderBookTest, TradeQuantityEqual) {

    OrderBook orderBook(2);

    orderBook.addOrder(Order (1, "AAPL", 155.0, 10, Order::BUY));
    orderBook.addOrder(Order (2, "AAPL", 150.0, 10, Order::SELL));

    std::this_thread::sleep_for(std::chrono::seconds(wait_time));

    std::vector<Trade> trades = orderBook.getExecutedTrades();
    EXPECT_EQ(trades.size(), 1);
    EXPECT_EQ(trades[0].getQuantity(), 10);
    // the trade should happen at best price availaible at the moment (Assumption#1).
    EXPECT_EQ(trades[0].getPrice(), 155);
    EXPECT_EQ(trades[0].getBuyOrderId(), 1);
    EXPECT_EQ(trades[0].getSellOrderId(), 2);

}

// Validating the assumption we took in ProcessSellOrder method. 
// (Assumption#2) 
TEST(OrderBookTest, TradeQuantityPriceAssuumption) {

    OrderBook orderBook(2);

    orderBook.addOrder(Order (1, "AAPL", 150.0, 10, Order::SELL));
    orderBook.addOrder(Order (2, "AAPL", 155.0, 10, Order::BUY));

    // Wait for threads to process
    std::this_thread::sleep_for(std::chrono::seconds(wait_time));

    // No trades should be executed since prices don't match
    std::vector<Trade> trades = orderBook.getExecutedTrades();
    EXPECT_EQ(trades.size(), 1);
    EXPECT_EQ(trades[0].getQuantity(), 10);

    // the trade should happen at best price availaible at the moment.
    EXPECT_EQ(trades[0].getPrice(), 150);
}

// No trade between different assets
TEST(OrderBookTest, TradeAssetDifferent) {

    OrderBook orderBook(2);

    orderBook.addOrder(Order (1, "AAPL", 155.0, 10, Order::BUY));
    orderBook.addOrder(Order (2, "TATA", 150.0, 10, Order::SELL));

    std::this_thread::sleep_for(std::chrono::seconds(wait_time));

    std::vector<Trade> trades = orderBook.getExecutedTrades();
    EXPECT_EQ(trades.size(), 0);
}

// Multiple orders summing to total required Volumne
TEST(OrderBookTest, TradeEqualVolume ) {
    OrderBook orderBook(2);

    orderBook.addOrder(Order (1, "AAPL", 152.0, 12, Order::BUY));
    orderBook.addOrder(Order (2, "AAPL", 155.0, 8, Order::BUY));
    orderBook.addOrder(Order (3, "AAPL", 150.0, 20, Order::SELL));

    std::this_thread::sleep_for(std::chrono::seconds(wait_time));

    std::vector<Trade> trades = orderBook.getExecutedTrades();
    EXPECT_EQ(trades.size(), 2);
    // Order offering higher price should execute first
    EXPECT_EQ(trades[0].getQuantity(), 8); 
    EXPECT_EQ(trades[0].getPrice(), 155);
    EXPECT_EQ(trades[1].getQuantity(), 12);
    EXPECT_EQ(trades[1].getPrice(), 152);
}

// Test to check for partially filled orders (Excess Volumne).
TEST(OrderBookTest, TradeExcessVolume ) {
    OrderBook orderBook(2);

    orderBook.addOrder(Order (1, "AAPL", 152.0, 12, Order::BUY));
    orderBook.addOrder(Order (2, "AAPL", 155.0, 8, Order::BUY));
    orderBook.addOrder(Order (3, "AAPL", 150.0, 25, Order::SELL));
    // partially filled order 3 shoul be used for below  
    orderBook.addOrder(Order (2, "AAPL", 158.0, 5, Order::BUY));

    std::this_thread::sleep_for(std::chrono::seconds(wait_time));

    std::vector<Trade> trades = orderBook.getExecutedTrades();
    EXPECT_EQ(trades.size(), 3);
    // Order offering higher price should execute first
    EXPECT_EQ(trades[0].getQuantity(), 8); 
    EXPECT_EQ(trades[0].getPrice(), 155);
    EXPECT_EQ(trades[1].getQuantity(), 12);
    EXPECT_EQ(trades[1].getPrice(), 152);
    EXPECT_EQ(trades[2].getQuantity(), 5); 
    EXPECT_EQ(trades[2].getPrice(), 150); // Price should be 150 (#Assumption2)
}

// Test to check for partially filled orders (Less than offered).
TEST(OrderBookTest, TradeDeficientVolume ) {
    OrderBook orderBook(2);

    orderBook.addOrder(Order (1, "AAPL", 152.0, 12, Order::BUY));
    orderBook.addOrder(Order (2, "AAPL", 155.0, 8, Order::BUY));
    orderBook.addOrder(Order (3, "AAPL", 150.0, 18, Order::SELL));

    std::this_thread::sleep_for(std::chrono::seconds(wait_time));

    std::vector<Trade> trades = orderBook.getExecutedTrades();
    EXPECT_EQ(trades.size(), 2);
    // Order offering higher price should execute first
    EXPECT_EQ(trades[0].getQuantity(), 8); 
    EXPECT_EQ(trades[0].getPrice(), 155);
    EXPECT_EQ(trades[1].getQuantity(), 10);
    EXPECT_EQ(trades[1].getPrice(), 152);
}

// Test to check if prices are same then earlier placed order executes first;
TEST(OrderBookTest, ProcesEarlierTimeStampFirst) {
    OrderBook orderBook(2);

    orderBook.addOrder(Order (1, "AAPL", 152.0, 5, Order::BUY));
    orderBook.addOrder(Order (2, "AAPL", 152.0, 5, Order::BUY));
    orderBook.addOrder(Order (3, "AAPL", 152.0, 5, Order::BUY));

    orderBook.addOrder(Order (4, "AAPL", 150.0, 25, Order::SELL));

    std::this_thread::sleep_for(std::chrono::seconds(wait_time));

    std::vector<Trade> trades = orderBook.getExecutedTrades();
    EXPECT_EQ(trades.size(), 3);
    // Order offering higher price should execute first
    EXPECT_EQ(trades[0].getBuyOrderId(), 1);
    EXPECT_EQ(trades[0].getSellOrderId(), 4);
    EXPECT_EQ(trades[1].getBuyOrderId(), 2);
    EXPECT_EQ(trades[1].getSellOrderId(), 4);
    EXPECT_EQ(trades[2].getBuyOrderId(), 3);
    EXPECT_EQ(trades[2].getSellOrderId(), 4);
}