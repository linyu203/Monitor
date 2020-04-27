
#ifndef INCLUDED_OVERSIZED_EXECUTION_H
#define INCLUDED_OVERSIZED_EXECUTION_H

#include <unordered_map>

#include "rule.h"

class OSE : public Rule {
  private:
  	std::unordered_map<int, int> d_remainVolume;
  	
  public:
  	OSE(std::vector<std::shared_ptr<Action>>& act, const Market& mkt):Rule(act,mkt){}
  	void check(std::shared_ptr<const Event> event);
};

#endif
