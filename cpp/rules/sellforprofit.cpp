
#include <sstream>
#include <iomanip>

#include "sellforprofit.h"

void SellForProfit::check(std::shared_ptr<const Event> event){
    using namespace std;
    if(e_EXECUTE != event->getEventType()){
        return ;
    }
    shared_ptr<const Execute> pExe = dynamic_pointer_cast<const Execute>(event);
    const string key = getKey(pExe);
    const Date& curDt = pExe->getDateTime().d_date;
    const double curPr = pExe->price();
    int curVol = pExe->volume();
    if(pExe->isBuy()){
        d_data[key].push(BuyRecord(curVol, curPr, curDt));
        return ;
    }
    queue<BuyRecord>& qBuyRcd = d_data[key];
    bool violated = false;
    while(!qBuyRcd.empty() && curVol > 0){
        BuyRecord & buyRcd = qBuyRcd.front();
        if( !violated && (curPr > buyRcd.d_price)
            && (curDt - buyRcd.d_date < 30)) {
            violated = true;
            stringstream ss;
            ss << "Sell For Profit: order " << pExe->client()
               << " Sold '" << pExe->parsekey() << "' within 30 days"
               << " Bought on " << buyRcd.d_date.getString()
               << " at $" << fixed << setprecision(2)
               << buyRcd.d_price << " sold on " << curDt.getString()
               << " at $" <<curPr;
            takeActions(ss.str());
        }
        if(curVol >= buyRcd.d_volume){
            curVol -= buyRcd.d_volume;
            qBuyRcd.pop();
        }else{
            buyRcd.d_volume -= curVol;
            return;
        }
    }
}


