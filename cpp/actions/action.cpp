#include "printaction.h"

std::vector<std::shared_ptr<Action>> initActions(void){
    std::vector<std::shared_ptr<Action>> actions;
    actions.push_back(std::make_shared<PrintAction>());
    return actions;
}

