#ifndef INCLUDED_MARKETE_H
#define INCLUDED_MARKETE_H

#include <string>
#include <memory>
#include <unordered_map>
#include "events/Order.h"

class Market {
  private:
    std::unordered_map<std::string, double> d_marketPrice;
   	std::unordered_map<int, std::shared_ptr<Order>> d_orderRecord;

  public:
  	Market(){};
	double getPrice(const std::string& s) const;
	std::shared_ptr<const Order> getOrder(int orderId) const;
	void setPrice(const std::string& s, double price);
	void addOrder(int orderId, std::shared_ptr<Order> order);
};

#endif
