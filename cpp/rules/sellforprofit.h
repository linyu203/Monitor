#ifndef INCLUDED_MISMATCHED_EXECUTION_H
#define INCLUDED_MISMATCHED_EXECUTION_H

#include "rule.h"
#include <unordered_map>
#include <queue>
#include <string>

struct BuyRecord {
    int d_volume;
	const double d_price;
	const Date d_date;
	BuyRecord(int vol, double p, const Date& d):
		d_volume(vol), d_price(p), d_date(d){}
};

class SellForProfit : public Rule {
  private:
  	std::unordered_map<std::string, std::queue<BuyRecord>> d_data;
	std::string getKey(std::shared_ptr<Execute> &exe)const{
		return exe->client() + "|" + exe->parsekey();
    }

  public:
  	SellForProfit(std::vector<std::shared_ptr<Action>>& act, const Market& mkt):Rule(act,mkt){}
  	void check(std::shared_ptr<const Event> event);
};

#endif
