#ifndef INCLUDED_PRINT_ACTION_H
#define INCLUDED_PRINT_ACTION_H

#include <string>
#include "action.h"

class PrintAction : public Action {
  public:
	void takeAction(const std::string& s)const;
};



#endif

