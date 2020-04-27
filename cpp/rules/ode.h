#ifndef INCLUDED_ORDER_EXPIRED_H
#define INCLUDED_ORDER_EXPIRED_H

#include "rule.h"

class ODE : public Rule {
  public:
  	ODE(std::vector<std::shared_ptr<Action>>& act, const Market& mkt):Rule(act,mkt){}
  	void check(std::shared_ptr<const Event> event);
};

#endif
