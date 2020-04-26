#ifndef INCLUDED_ACTION_H
#define INCLUDED_ACTION_H

#include <string>
#include <vector>
#include <memory>

class Action {
  public:
  	virtual ~Action()=0;
	void takeAction(const std::string& s)const = 0;
};
std::vector<std::shared_ptr<Action>> initActions(void);


#endif
