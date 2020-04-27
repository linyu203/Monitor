#ifndef INCLUDED_MISMATCHED_EXECUTION_H
#define INCLUDED_MISMATCHED_EXECUTION_H

#include "rule.h"
#include <queue>
#include <unordered_map>


struct VolumeHistory{
    int d_sum;
	int d_curVol;
	std::queue<int>d_qvHis;
	VolumeHistory(){}
	void update(void){
		if(d_curVol == 0){
			return;
	    }
		d_sum += d_curVol;
		d_qvHis.push(d_curVol);
		d_curVol = 0;
		if(d_qvHis.size()>4){
			d_sum -= d_qvHis.front();
			d_qvHis.pop();
		}
	}
	void increment(int vol){
		d_curVol += vol;
	}
};

class Domination : public Rule {
  private:
  	Date d_curDate;
    std::unordered_map<std::string, int>d_currentVol;
	std::unordered_map<std::string, VolumeHistory>d_volHis;
	void updateData(const Date& dt);
	std::string getKey(std::shared_ptr<const Execute> &exe)const{
		return exe->broker() + "|" + exe->parsekey();
    }
	
  public:
  	Domination(std::vector<std::shared_ptr<Action>>& act, const Market& mkt):Rule(act,mkt){}
  	void check(std::shared_ptr<const Event> event);
};

#endif
