#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <ctime>
#include "../src/trade.h"

// checking constructor
TEST(TradeTest, CreateTrade) {
    Trade trade("BTC", 50000, 5, std::time(nullptr), 1, 2);

    EXPECT_EQ(trade.getAsset(), "BTC");
    EXPECT_EQ(trade.getPrice(), 50000);
    EXPECT_EQ(trade.getQuantity(), 5);
    EXPECT_EQ(trade.getBuyOrderId(),1);
    EXPECT_EQ(trade.getSellOrderId(),2);
}

TEST(TradeTest, PrintTrade) {
    std::time_t currentTime = std::time(nullptr);
    Trade trade("BTC", 50000, 5, currentTime, 101, 202);

    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    trade.printTrade();

    std::cout.rdbuf(oldCoutBuffer);

    char* expectedTimestamp = std::ctime(&currentTime);

    std::ostringstream expectedOutput;
    expectedOutput << "Trade - Asset: BTC, Price: 50000, Quantity: 5, Timestamp: "
                   << expectedTimestamp
                   << ", Buy Order Id: 101, Sell Order Id: 202"<<std::endl;

    ASSERT_EQ(output.str(), expectedOutput.str());
}
