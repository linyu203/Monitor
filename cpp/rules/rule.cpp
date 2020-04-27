
#include "invalidexecution.h"
#include "mismatchedexecution.h"
#include "oversizedexecution.h"
#include "orderexpired.h"
#include "sellforprofit.h"
#include "abnormalprice.h"
#include "domination.h"

std::vector<std::shared_ptr<Rule>> initRules(
    std::vector<std::shared_ptr<Action>>& act, 
    const Market& mkt) {
    std::vector<std::shared_ptr<Rule>> rules;
    rules.push_back(std::make_shared<InvalidExecution>(act,mkt));
    rules.push_back(std::make_shared<MismatchedExecution>(act,mkt));
    rules.push_back(std::make_shared<OversizedExecution>(act,mkt));
    rules.push_back(std::make_shared<OrderExpired>(act,mkt));
    rules.push_back(std::make_shared<SellForProfit>(act,mkt));
    rules.push_back(std::make_shared<AbnormalPrice>(act,mkt));
    rules.push_back(std::make_shared<Domination>(act,mkt));
    return rules;
}

void Rule::takeActions(const std::string& s){
    for(auto& act:d_actions){
        act->takeAction(s);
    }
}

