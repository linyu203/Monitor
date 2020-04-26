#include "parse.h"
#include "events/order.h"
#include "events/execute.h"
#include "events/price.h"


bool getNext(const std::string& s, int& initPos, const char c, std::string& getS){
    if(initPos >= s.size()){
        return -1;
    }
    int p = initPos;
    while(p < s.size()){
        if(s[p] == c){
            break;
        }
        p++;
    }
    getS = s.substr(initPos, p-initPos);
    initPos = p+1;
    return true;
}

int countBreak(const std::string& s, int st, const char c){
    if(s.empty()){
        return -1;
    }
    int cnt = 0;
    while(st<s.size()){
        if(s[st++] == c)
            cnt++;
    }
    return cnt;
}

std::shared_ptr<Event> parsePrice(const std::string& s, int st){
    using namespace std;
    const char c = '|';
    string dt;
    string tmp;
    getNext(s,st,c,dt);
    getNext(s,st,c,tmp);
    dt += "|" + tmp;
    getNext(s,st,c,tmp);
    string psk = tmp;
    getNext(s,st,c,tmp);
    double pri = stod(tmp);
    return make_shared<Price>(dt, psk, pri);
}

std::shared_ptr<Event> parseTrancestion(
    const std::string& s, int st, 
    Event_Type e_evenType){
    using namespace std;
    const char c = '|';

    string tmp;
    getNext(s,st,c,tmp);
    int id = stoi(tmp);
    string dt;
    getNext(s,st,c,dt);
    getNext(s,st,c,tmp);
    dt += "|" + tmp;
    getNext(s,st,c,tmp);
    string cli = tmp;
    getNext(s,st,c,tmp);
    string bro = tmp;
    getNext(s,st,c,tmp);
    bool isBuy = tmp=="BUY";
    getNext(s,st,c,tmp);
    string psk = tmp;
    getNext(s,st,c,tmp);
    int vol = stoi(tmp);
    getNext(s,st,c,tmp);
    double pri = -1.0;
    if(tmp != "MKT")
        pri = stod(tmp);
    
    if(e_evenType == e_ORDER){
        return make_shared<Order>(id, dt, cli, bro, isBuy, psk, vol, pri);
    }
    return make_shared<Execute>(id, dt, cli, bro, isBuy, psk, vol, pri);
}

std::shared_ptr<Event> parse(const std::string& s){
    using namespace std;
    const char c = '|';
    const int brk = countBreak(s,0,c);
    string tmp;
    int pos = 0;
    if(getNext(s,pos,c,tmp)){
        if("ORDER" == tmp){
            if(brk != 9){
                return nullptr;
            }
            return parseTrancestion(s,pos,e_ORDER);
        }else if("EXECUTE" == tmp){
            if(brk != 9){
                return nullptr;
            }
            return parseTrancestion(s,pos,e_EXECUTE);
        }else if("PRICE" == tmp){
            if(brk != 4){
                return nullptr;
            }
            return parsePrice(s,pos);
        }
    }
    return nullptr;
}

