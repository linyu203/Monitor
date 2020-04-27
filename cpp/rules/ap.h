#ifndef INCLUDED_AP_H
#define INCLUDED_AP_H

#include "rule.h"

class AP : public Rule {
  public:
  	AP(std::vector<std::shared_ptr<Action>>& act, const Market& mkt):Rule(act,mkt){}
  	void check(std::shared_ptr<const Event> event);
};

#endif

