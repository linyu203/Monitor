package rule

import (
    ev "events"
    "fmt"
    "time"
)

type hisVolList struct{
    totalVolume int
	curVolume   int
	qhisVolume  []int
}
func makeHisVolList() *hisVolList{
    his := hisVolList{}
	his.totalVolume = 0
	his.curVolume = 0
	his.qhisVolume = make([]int, 0, 4)
	return &his
}
func (his *hisVolList)increment(vol int){
    his.curVolume += vol
}
func (his *hisVolList)update(){
    if his.curVolume == 0 {
	    return 
	}
	if len(his.qhisVolume) == 4{
	    his.totalVolume -= his.qhisVolume[0]
		his.qhisVolume = [1:]
	}
	his.totalVolume += his.curVolume
	his.qhisVolume = append(his.qhisVolume,his.curVolume)
	his.curVolume = 0
}
func (his *hisVolList)getAverage()(tVol, cnt int){
    cnt = len(his.qhisVolume)
	tVol = his.totalVolume
	return
}
type Rsfp struct{
    dailyVolume map[string]*int
	hisVolume map[string]*hisVolList
	curY,curM,curD int
}
func getDailyKey(evn *ev.Event)string{
    return evn.Broker + "|" + evn.Security
}
func (r *Rsfp)Rupdate(nd * time.Time){
    y,m,d := nd.Date()
	if curD == d && curM == m && curY == y {
	    return
	}
	curY = y
	curM = m
	curD = d
	dailyVolume.Clear()
	for _,v := range r.hisVolList {
	    v.update()
	}
}
func InitRsfp()Rule{
    rsfp := Rsfp{}
    rsfp.dailyVolume = make(map[string]*int)
	rsfp.hisVolume = make(map[string]*hisVolList)
    return &rsfp
}

func (r *Rsfp) CheckEvent(evn *ev.Event) (sr string){
    if evn.EventType != ev.EVENT_EXECUTE {
        return
    }
	r.Rupdate(&evn.EventTime)
	nVol := evn.Volume
    key := r.getDailyKey(evn)
	daVol,ok := r.dailyVolume[key]
	if !ok {
	    r.dailyVolume[key] = &nVol
		daVol = &nVol
	} else {
	    *daVol += nVol
	}
    hiVol,ok := r.hisVolume[evn.Security]
	if !ok {
	    hisVol = makeHisVolList()
		r.hisVolume[evn.Security] = hisVol
	}
	hisVol.increment(evn.Volume)
	tlVol, cnt = hisVol.getAverage()
	if cnt > 0 && *daVol * cnt > 1.5 * tlVol {
	    sr = fmt.Sprintf("D M N: %v has executed over 50% of the average volume for '%v', the total volume %v, the average is %.2f",
		     evn.Broker, evn.Security, *daVol, tlVol/cnt)
	}
    return
}

