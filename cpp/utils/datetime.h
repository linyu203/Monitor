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
};


class Time{
  public:
  	int d_hour;
	int d_minute;
	int d_second;
	const std::string d_timeString;
	Time(){};
	void setTime(const std::string& s);
	const std::string& getString(void)const{
		return d_timeString;
	}

};

class DateTime{
  private:
	
  public:
  	Date d_date;
	Time d_time;
  	explicit DateTime(const std::string& s);
};

#endif

