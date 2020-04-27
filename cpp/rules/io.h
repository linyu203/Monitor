#ifndef INCLUDED_INVALID_EXECUTION_H
#define INCLUDED_INVALID_EXECUTION_H

#include "rule.h"

class IO : public Rule {
  public:
  	IO(std::vector<std::shared_ptr<Action>>& act, const Market& mkt):Rule(act,mkt){}
  	void check(std::shared_ptr<const Event> event);
};

#endif
