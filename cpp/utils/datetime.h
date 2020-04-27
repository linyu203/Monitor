#ifndef INCLUDED_DATETIME_H
#define INCLUDED_DATETIME_H

#include <string>

class Date{
  public:
  	int d_year;
	int d_month;
	int d_day;
	//Date(const string& s);
    std::string d_dateString;
	Date(){};
	void setDate(const std::string& s);
	const std::string& getString(void)const{
		return d_dateString;
	}
	bool operator== (const Date& o_dt){
		return o_dt.d_dateString == this->d_dateString;
	}
	bool operator!= (const Date& o_dt){
		return !(*this == o_dt);
	}
	friend bool operator< (const Date& cur, const Date& o_dt){
		if(cur.d_year != o_dt.d_year)
			return cur.d_year < o_dt.d_year;
		if(cur.d_month != o_dt.d_month)
			return cur.d_month < o_dt.d_month;
		return cur.d_day < o_dt.d_day;
		
	}
	friend int operator- (const Date& cur, const Date& o_dt);
};


class Time{
  public:
  	int d_hour;
	int d_minute;
	int d_second;
	std::string d_timeString;
	Time(){};
	void setTime(const std::string& s);
	const std::string& getString(void)const{
		return d_timeString;
	}
	bool operator== (const Time& o_tm){
		return o_tm.d_timeString == this->d_timeString;
	}
	bool operator!= (const Time& o_tm){
		return !(*this == o_tm);
	}
    int operator- (const Time& o_tm);
};

class DateTime{
  private:
	
  public:
  	Date d_date;
	Time d_time;
  	explicit DateTime(const std::string& s);
};

#endif

