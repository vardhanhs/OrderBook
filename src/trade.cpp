#include "trade.h"

// Constructor
Trade::Trade(const std::string &asset, double price, int quantity, std::time_t timestamp,
             int buyOrderId, int sellOrderId)
    : asset(asset), price(price), quantity(quantity), timestamp(timestamp),
      buyOrderId(buyOrderId), sellOrderId(sellOrderId) {}

// Print trade
void Trade::printTrade() const
{
    std::cout << "Trade - Asset: " << asset << ", Price: " << price
              << ", Quantity: " << quantity << ", Timestamp: "
              << std::ctime(&timestamp)
              << ", Buy Order Id: "<<buyOrderId
              <<", Sell Order Id: "<<sellOrderId
              << std::endl;
}

// Getters
std::string Trade::getAsset() const { return asset; }
double Trade::getPrice() const { return price; }
int Trade::getQuantity() const { return quantity; }
std::time_t Trade::getTimestamp() const { return timestamp; }
int Trade::getBuyOrderId() const { return buyOrderId; }
int Trade::getSellOrderId() const { return sellOrderId; }
