#include "monitor.h"
#include "parse.h"
#include "events/order.h"
#include "events/price.h"


Monitor::Monitor(){
    d_actions = initActions();
    d_rules = initRules(d_actions, d_market);
}

void Monitor::checkRules(std::shared_ptr<const Event> event){
    for(auto &r:d_rules){
        r->check(event);
    }
}


void Monitor::parseEvent(const std::string& s){
    using namespace std;
    shared_ptr<Event> pEvent = parse(s);
    if(pEvent == nullptr){
        throw invalid_argument("parse event failed!");
    }
    const Event_Type evType = pEvent->getEventType();
    if(evType == e_ORDER){
        shared_ptr<Order> pOrder = dynamic_pointer_cast<Order>(pEvent);
        d_market.addOrder(pOrder->orderId(), pOrder);
    }else if(evType == e_EXECUTE){
        checkRules(pEvent);
    }else if(evType == e_PRICE){
        shared_ptr<Price> pPrice = dynamic_pointer_cast<Price>(pEvent);
        d_market.setPrice(pPrice->parsekey(), pPrice->price());
    }else{
        throw invalid_argument("event type not support!");
    }
}
