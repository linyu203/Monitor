#ifndef INCLUDED_RULE_H
#define INCLUDED_RULE_H

#include <string>
#include <memory>
#include <vector>

#include "../events/market.h"
#include "../events/execute.h"

#include "../actions/action.h"



class Rule{
  private:
  	const std::vector<std::shared_ptr<Action>>& d_actions;
	
  public:
  	Rule(std::vector<std::shared_ptr<Action>>& act, const Market& mkt)
		:d_actions(act), d_market(mkt){}
	virtual ~Rule(){};
	virtual void check(std::shared_ptr<const Event> event) = 0;
	void takeActions(const std::string& s);
	const Market& d_market;
};

std::vector<std::shared_ptr<Rule>> initRules(
	std::vector<std::shared_ptr<Action>>& act, 
	const Market& mkt);


#endif
