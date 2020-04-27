#include "invalidexecution.h"

void InvalidExecution::check(std::shared_ptr<const Event> event){
    if(e_EXECUTE != event->getEventType()){
        return ;
    }
    std::shared_ptr<const Execute> pExe = std::dynamic_pointer_cast<const Execute>(event);
    int id = pExe->orderId();
    if(!d_market.getOrder(id)){
        takeActions("Order id:" + std::to_string(id) + " is not valid");
    }
}

