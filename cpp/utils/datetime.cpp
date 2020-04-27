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
    d_dateString = to_string(d_year);
}

void Time::setTime(const std::string& s){
    using namespace std;
    d_timeString = s;
    d_hour   = stoi(s.substr(0,2));
    d_minute = stoi(s.substr(3,2));
    d_second = stoi(s.substr(6,2));
}

