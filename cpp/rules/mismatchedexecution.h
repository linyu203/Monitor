#ifndef INCLUDED_MISMATCHED_EXECUTION_H
#define INCLUDED_MISMATCHED_EXECUTION_H

#include "rule.h"

class MismatchedExecution : public Rule {
  public:
  	MismatchedExecution(std::vector<std::shared_ptr<Action>>& act, const Market& mkt):Rule(act,mkt){}
  	void check(std::shared_ptr<const Event> event);
};

#endif
