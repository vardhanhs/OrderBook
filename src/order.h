#pragma once

#include <string>
#include <ctime>

class Order {
public:
    enum OrderType { BUY, SELL };
    
private:
    int id;
    std::string asset;
    double price;
    int quantity;
    OrderType type;
    std::time_t timestamp;

public:
    Order(int id, const std::string& asset, double price, int quantity, OrderType type);
    
    void reduceQuantity(int qty);

    // Getters
    int getId() const;
    std::string getAsset() const;
    double getPrice() const;
    int getQuantity() const;
    OrderType getType() const;
    std::time_t getTimestamp() const;

};
