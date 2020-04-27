
#include <sstream>
#include <iomanip>

#include "em.h"

void EM::check(std::shared_ptr<const Event> event){
    using namespace std;

    if(e_EXECUTE != event->getEventType()){
        return ;
    }
    shared_ptr<const Execute> pExe = dynamic_pointer_cast<const Execute>(event);
    int id = pExe->orderId();
    shared_ptr<const Order> pOrder = d_market.getOrder(id);
    if(pOrder == nullptr){
        return ;
    }
    string fields;
    if(pOrder->client() != pExe->client()){
        fields += " client";
    }
    if(pOrder->broker() != pExe->broker()){
        fields += " broker";
    }
    if(pOrder->isBuy() != pExe->isBuy()){
        fields += " type";
    }
    if(pOrder->parsekey() != pExe->parsekey()){
        fields += " parsekey";
    }
    if(pOrder->volume() < pExe->volume()){
        fields += " volume";
    }
    if(pOrder->price() >= 0.0 && pOrder->price() != pExe->price()){
        fields += " price";
    }
    if(fields.empty()){
        return ;
    }
    stringstream ss;
    ss << "EM: order " << id 
    << " is not matched with the order, mismatched fields:"
    << fields;
    takeActions(ss.str());
}


