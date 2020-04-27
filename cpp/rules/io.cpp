
#include <sstream>
#include "io.h"

void IO::check(std::shared_ptr<const Event> event){
    if(e_EXECUTE != event->getEventType()){
        return ;
    }
    std::shared_ptr<const Execute> pExe = std::dynamic_pointer_cast<const Execute>(event);
    int id = pExe->orderId();
    if(!d_market.getOrder(id)){
        std::stringstream ss;
        ss<<"I O: order " << id <<" is not valid";
        takeActions(ss.str());
    }
}

