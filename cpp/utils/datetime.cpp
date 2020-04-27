#include "datetime.h"

DateTime::DateTime(const std::string& s){
    d_date.setDate(s.substr(0,8));
    d_time.setTime(s.substr(9));
}
const std::string g_MonthName[13] = {
    "",
    "JAN",
    "FEB",
    "MAR",
    "APR",
    "MAY",
    "JUN",
    "JUL",
    "AUG",
    "SEP",
    "OCT",
    "NOV",
    "DEC",
};
void Date::setDate(const std::string& s){
    using namespace std;
    d_year  = stoi(s.substr(0,4));
    d_month = stoi(s.substr(4,2));
    d_day   = stoi(s.substr(6,2));
    if(d_day<10){
        d_dateString = "0" + to_string(d_day);
    }else{
        d_dateString = to_string(d_day);
    }
    d_dateString += g_MonthName[d_month];
    d_dateString += to_string(d_year);
}

void Time::setTime(const std::string& s){
    using namespace std;
    d_timeString = s;
    d_hour   = stoi(s.substr(0,2));
    d_minute = stoi(s.substr(3,2));
    d_second = stoi(s.substr(6,2));
}

bool isLeapYear(int year){
    if(year%400 == 0){
        return true;
    }
    if(year%100 == 0){
        return false;
    }
    return year%4==0;
}

const int g_countMonth[13] = {
    0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334,
};

int operator- (const Date& cur, const Date& o_dt){
    if(cur < o_dt){
        return -1;
    }
    int sty = o_dt.d_year;
    int stm = o_dt.d_month;
    int std = o_dt.d_day;
    int edy = cur.d_year;
    int edm = cur.d_month;
    int edd = cur.d_day;
    int stdays = std + g_countMonth[stm];
    if(isLeapYear(sty) && stm>=3){
        stdays++;
    }
    int eddays = edd + g_countMonth[edm];
    if(isLeapYear(edy) && edm>=3){
        eddays++;
    }
    while(sty<edy){
        eddays += 365;
        if(isLeapYear(sty)){
            eddays++;
        }
        sty++;
    }
    return eddays - stdays;
}

int Time::operator- (const Time& o_tm){
    int dh = this->d_hour - o_tm.d_hour;
    int dm = this->d_minute - o_tm.d_minute;
    int ds = this->d_second - o_tm.d_second;
    return dh*3600+dm*60+ds;
}


