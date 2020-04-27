
#include "io.h"
#include "em.h"
#include "ose.h"
#include "ode.h"
#include "sfp.h"
#include "ap.h"
#include "dmn.h"

std::vector<std::shared_ptr<Rule>> initRules(
    std::vector<std::shared_ptr<Action>>& act, 
    const Market& mkt) {
    std::vector<std::shared_ptr<Rule>> rules;
    rules.push_back(std::make_shared<IO>(act,mkt));
    rules.push_back(std::make_shared<EM>(act,mkt));
    rules.push_back(std::make_shared<OSE>(act,mkt));
    rules.push_back(std::make_shared<ODE>(act,mkt));
    rules.push_back(std::make_shared<SFP>(act,mkt));
    rules.push_back(std::make_shared<AP>(act,mkt));
    rules.push_back(std::make_shared<DMN>(act,mkt));
    return rules;
}

void Rule::takeActions(const std::string& s){
    for(auto& act:d_actions){
        act->takeAction(s);
    }
}

