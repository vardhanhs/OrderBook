#pragma once

#include <iostream>
#include <string>
#include <ctime>

class Trade
{
private:
    //(TODO) Change assests from string to predefined types/enums.
    std::string asset;
    double price;
    int quantity;
    std::time_t timestamp;
    int buyOrderId;
    int sellOrderId;

public:
    Trade(const std::string &asset, double price, int quantity, std::time_t timestamp,
          int buyOrderId, int sellOrderId);
    void printTrade() const;

    std::string getAsset() const;
    double getPrice() const;
    int getQuantity() const;
    std::time_t getTimestamp() const;
    int getBuyOrderId() const;
    int getSellOrderId() const;
};
