
#include <sstream>
#include <iomanip>

#include "domination.h"

void Domination::updateData(const Date& dt){
    if(d_curDate == dt){
        return ;
    }
    d_curDate = dt;
    d_currentVol.clear();
    for(auto& it:d_volHis){
        it.second.update();
    }
}


void Domination::check(std::shared_ptr<const Event> event){
    using namespace std;

    if(e_EXECUTE != event->getEventType()){
        return ;
    }
    shared_ptr<const Execute> pExe = dynamic_pointer_cast<const Execute>(event);
    const Date& curDt = pExe->getDateTime().d_date;
    updateData(curDt);
    const string key = getKey(pExe);
    const int curVol = (d_currentVol[key] += pExe->volume());
    VolumeHistory& vh = d_volHis[pExe->parsekey()];
    vh.increment(pExe->volume());
    int sum = vh.d_sum;
    int cnt = vh.d_qvHis.size();
    if(cnt>0 && curVol*cnt > 1.5 * sum){
        stringstream ss;
        ss << "Domination: " << pExe->broker() 
           << " has executed over 50% of the average volume for '"
           << pExe->parsekey() << "', the total volume "
           << curVol << ", the average is "
           << fixed << setprecision(2) << (sum*1.0/cnt);
        takeActions(ss.str());
    }
}


