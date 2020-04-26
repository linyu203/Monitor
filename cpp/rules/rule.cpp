#include "invalidExecution.h"
#include "abnormalprice.h"



std::vector<std::shared_ptr<Rule>> initRules(
    std::vector<std::shared_ptr<Action>>& act, 
    const Market& mkt) {
    std::vector<std::shared_ptr<Rule>> rules;
    rules.push_back(std::make_shared<InvalidExecution>(act,mkt));
    rules.push_back(std::make_shared<AbnormalPrice>(act,mkt));
    return rules;
}

void Rule::takeActions(const std::string& s){
    for(auto& act:d_actions){
        act->takeAction(s);
    }
}

