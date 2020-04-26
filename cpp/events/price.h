#ifndef INCLUDED_PRICE_H
#define INCLUDED_PRICE_H

#include <string>
#include "event.h"


class Price : public Event{
  private:
    const double d_price;
	const std::string d_parsekey;
	
  public:
  	Price(const std::string& dt, const std::string& psk, double pri) :Event(dt), d_price(pri), d_parsekey(psk){}
	Event_Type getEventType(void)const{return e_PRICE;}
	const std::string& parsekey(void)const{return d_parsekey;}
	double price()const{return d_price;}
};

#endif
