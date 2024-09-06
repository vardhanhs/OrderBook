#pragma once

#include <iostream>
#include <string>
#include <ctime>

class Trade {
private:
    //(TODO) Change assests from string to predefined types/enums.
    std::string asset;
    double price;
    int quantity;
    std::time_t timestamp;

public:
    Trade(const std::string& asset, double price, int quantity, std::time_t timestamp);
    void printTrade() const;

};
