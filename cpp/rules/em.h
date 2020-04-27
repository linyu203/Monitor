#ifndef INCLUDED_EM_H
#define INCLUDED_EM_H

#include "rule.h"

class EM : public Rule {
  public:
  	EM(std::vector<std::shared_ptr<Action>>& act, const Market& mkt):Rule(act,mkt){}
  	void check(std::shared_ptr<const Event> event);
};

#endif
