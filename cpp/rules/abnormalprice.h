#ifndef INCLUDED_ABNORMAL_PRICE_H
#define INCLUDED_ABNORMAL_PRICE_H

#include "rule.h"

class AbnormalPrice : public Rule {
  public:
  	AbnormalPrice(std::vector<std::shared_ptr<Action>>& act, const Market& mkt):Rule(act,mkt){}
  	void check(std::shared_ptr<const Event> event);
};

#endif

