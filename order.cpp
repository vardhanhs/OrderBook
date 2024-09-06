#include "order.h"

// Constructor for Order class
Order::Order(int id, const std::string& asset, double price, int quantity, OrderType type) 
    : id(id), asset(asset), price(price), quantity(quantity), type(type), timestamp(std::time(nullptr)) {}

// Reduce the quantity of the order after a partial match
void Order::reduceQuantity(int qty) {
    quantity -= qty;
}

// Getter implementations
int Order::getId() const { return id; }
std::string Order::getAsset() const { return asset; }
double Order::getPrice() const { return price; }
int Order::getQuantity() const { return quantity; }
Order::OrderType Order::getType() const { return type; }
std::time_t Order::getTimestamp() const { return timestamp; }
