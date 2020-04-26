#ifndef INCLUDED_ORDER_H
#define INCLUDED_ORDER_H

#include <string>
#include "event.h"

class Order : public Event{
  private:
    const int d_orderId;
    const std::string d_client;
    const std::string d_broker;
    const bool d_isBuy;
    const std::string d_parsekey;
    const int d_volume;
    const double d_price;
    
  public:
    Order(int id, const std::string& dt, const std::string& cli, const std::string& bro, 
            bool isb, const std::string& psk, int vol, double pri) 
		: Event(dt), d_orderId(id), d_client(cli), d_broker(bro),
          d_isBuy(isb), d_parsekey(psk), d_volume(vol), d_price(pri){}
    Event_Type getEventType(void)const{return e_ORDER;}
    int orderId(void)const{return d_orderId;}
    const std::string& client()const{return d_client;}
    const std::string& broker(void)const{return d_broker;}
    bool isBuy()const{return d_isBuy;}
    const std::string& parsekey(void)const{return d_parsekey;}

    int volume(void)const{return d_volume;}
    double price()const{return d_price;}
};


#endif
