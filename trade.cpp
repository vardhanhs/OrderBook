#include "trade.h"

// Constructor
Trade::Trade(const std::string& asset, double price, int quantity, std::time_t timestamp)
    : asset(asset), price(price), quantity(quantity), timestamp(timestamp) {}

// Print trade
void Trade::printTrade() const {
    std::cout << "Trade - Asset: " << asset << ", Price: " << price
              << ", Quantity: " << quantity << ", Timestamp: "
              << std::ctime(&timestamp);
}
