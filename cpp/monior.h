#ifndef INCLUDED_MONITOR_H
#define INCLUDED_MONITOR_H

#include <string>
#include <memory>
#include <unordered_map>
#include <vector>


#include "rules/rule.h"
#include "events/event.h"
#include "actions/action.h"
#include "market.h"



class Monitor {
  private:
	Market d_market;
    std::vector<std::shared_ptr<Action>> d_actions;
	std::vector<std::shared_ptr<Rule>> d_rules;

    void checkRules(std::shared_ptr<Event> event);
	
  public:
  	Monitor();
	void parseEvent(const string& s);
};

#endif
