#ifndef INCLUDED_SELL_FOR_PROFIT_H
#define INCLUDED_SELL_FOR_PROFIT_H

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

class SFP : public Rule {
  private:
  	std::unordered_map<std::string, std::queue<BuyRecord>> d_data;
	std::string getKey(std::shared_ptr<const Execute> &exe)const{
		return exe->client() + "|" + exe->parsekey();
    }

  public:
  	SFP(std::vector<std::shared_ptr<Action>>& act, const Market& mkt):Rule(act,mkt){}
  	void check(std::shared_ptr<const Event> event);
};

#endif
