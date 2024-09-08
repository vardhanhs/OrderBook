#include <gtest/gtest.h>
#include "../src/order.h"

TEST(OrderTest, CreateBuyOrder) {
    Order buyOrder(1, "BTC", 50000, 10, Order::BUY);
    EXPECT_EQ(buyOrder.getId(), 1);
    EXPECT_EQ(buyOrder.getAsset(), "BTC");
    EXPECT_EQ(buyOrder.getPrice(), 50000);
    EXPECT_EQ(buyOrder.getQuantity(), 10);
    EXPECT_EQ(buyOrder.getType(), Order::BUY);
}

TEST(OrderTest, ReduceQuantity) {
    Order order(1, "BTC", 50000, 10, Order::BUY);
    order.reduceQuantity(5);
    EXPECT_EQ(order.getQuantity(), 5);
}