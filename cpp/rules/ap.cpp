
#include <sstream>
#include <iomanip>
#include "ap.h"

void AP::check(std::shared_ptr<const Event> event){
    using namespace std;
    if(e_EXECUTE != event->getEventType()){
        return ;
    }
    shared_ptr<const Execute> pExe = dynamic_pointer_cast<const Execute>(event);
    double cPrice = pExe->price();
    const string& psk = pExe->parsekey();
    double mktPrice = d_market.getPrice(psk);
    if(mktPrice > 0.0 && (mktPrice*2.0 < cPrice || mktPrice > 2.0 * cPrice)){
        stringstream ss;
        ss<<"A P: " << pExe->broker() 
        << " has executed $" << fixed << setprecision(2)
        << cPrice << " for '" << psk << "', while the market price is $"
        << mktPrice;
        takeActions(ss.str());
    }
}

