#ifndef INCLUDED_MISMATCHED_EXECUTION_H
#define INCLUDED_MISMATCHED_EXECUTION_H

#include "rule.h"

class OrderExpired : public Rule {
  public:
  	OrderExpired(std::vector<std::shared_ptr<Action>>& act, const Market& mkt):Rule(act,mkt){}
  	void check(std::shared_ptr<const Event> event);
};

#endif
