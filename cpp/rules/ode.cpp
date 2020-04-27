
#include <sstream>
#include <iomanip>

#include "ode.h"

void ODE::check(std::shared_ptr<const Event> event){
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
    Date dtExe = pExe->getDateTime().d_date;
    Date dtOrder = pOrder->getDateTime().d_date;
    Time tmExe = pExe->getDateTime().d_time;
    Time tmOrder = pOrder->getDateTime().d_time;
    bool isMKT = (pOrder->price() < 0.0);
    if(dtExe != dtOrder || (isMKT && (tmExe-tmOrder) >= 300)){
        stringstream ss;
        ss << "ODE: " << (isMKT ? "Market" : "Limit") 
        << " order expired, order was placed on " << dtOrder.getString()
        << " at " << tmOrder.getString() << " executed on "
        << dtExe.getString() << " at " << tmExe.getString();
        takeActions(ss.str());
    }
}


