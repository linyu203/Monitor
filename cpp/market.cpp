#include "market.h"

double Market::getPrice(const std::string& s) const{
    auto iter = d_marketPrice.find(s);
    if(iter == d_marketPrice.end()){
        return -1.0;
    }
    return iter->second;
}
std::shared_ptr<const Event> Market::getOrder(int orderId) const{
    auto iter = d_orderRecord.find(orderId);
    if(iter == d_orderRecord.end()){
        return nullptr;
    }
    return iter->second;
}
void Market::setPrice(const std::string& s, double price){
    d_marketPrice[s] = price;
}
void Market::addOrder(int orderId, std::shared_ptr<Order> order){
    d_orderRecord.insert({orderId, order});
}
