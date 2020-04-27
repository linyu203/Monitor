#ifndef INCLUDED_EVNET_H
#define INCLUDED_EVNET_H

#include <string>
#include "../utils/datetime.h"

enum Event_Type{
    e_ORDER = 0,
	e_EXECUTE = 1,
	e_PRICE = 2,
	e_EVENT_TYPE_MAX
};

class Event{
  private:
  	const DateTime d_dt;
	
  public:
  	Event(const std::string& s):d_dt(s){};
	virtual ~Event()=0;
	virtual Event_Type getEventType(void)const = 0;
	const DateTime& getDateTime(void)const{return d_dt;}
};

#endif
