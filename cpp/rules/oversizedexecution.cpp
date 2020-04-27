
#include <sstream>
#include <iomanip>

#include "oversizedexecution.h"

//d_remainVolume
void OversizedExecution::check(std::shared_ptr<const Event> event){
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
    auto iter = d_remainVolume.find(id);
    if(iter == d_remainVolume.end()){
        if((d_remainVolume[id] = pOrder->volume() - pExe->volume()) >= 0){
            return ;
        }
    }else{
        iter->second -= pExe->volume();
        if(iter->second >= 0){
            return ;
        }
    }
    stringstream ss;
    ss << "Oversized Execution: order " << id 
       << "has been executed oversized by " << pExe->broker();
    takeActions(ss.str());
}


