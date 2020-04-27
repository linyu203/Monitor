#include "abnormalprice.h"

void AbnormalPrice::check(std::shared_ptr<const Event> event){
    if(e_EXECUTE != event->getEventType()){
        return ;
    }
    std::shared_ptr<Execute> pExe = std::dynamic_pointer_cast<Execute>(event);
    double cPrice = pExe->price();
    const std::string& psk = pExe->persekey();
    double mktPrice = d_market.getPrice(psk);
    if(mktPrice > 0.0 && (mktPrice*2.0 < cPrice || mktPrice > 2.0 * cPrice)){
        takeActions(psk + " was Executed with abnormal price ");
    }
}

