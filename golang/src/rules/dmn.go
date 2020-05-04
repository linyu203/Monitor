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
        his.qhisVolume = his.qhisVolume[1:]
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
type Rdmn struct{
    dailyVolume map[string]*int
    hisVolume map[string]*hisVolList
    curY,curD int
    curM time.Month
}
func getDailyKey(evn *ev.Event)string{
    return evn.Broker + "|" + evn.Security
}
func (r *Rdmn)Rupdate(nd * time.Time){
    y,m,d := nd.Date()
    if r.curD == d && r.curM == m && r.curY == y {
        return
    }
    r.curY = y
    r.curM = m
    r.curD = d
    r.dailyVolume = make(map[string]*int)
    for _,v := range r.hisVolume {
        v.update()
    }
}
func InitRdmn()Rule{
    rdmn := Rdmn{}
    rdmn.dailyVolume = make(map[string]*int)
    rdmn.hisVolume = make(map[string]*hisVolList)
    return &rdmn
}

func (r *Rdmn) CheckEvent(evn *ev.Event) (sr string){
    if evn.EventType != ev.EVENT_EXECUTE {
        return
    }
    r.Rupdate(&evn.EventTime)
    nVol := evn.Volume
    key := getDailyKey(evn)
    daVol,ok := r.dailyVolume[key]
    if !ok {
        r.dailyVolume[key] = &nVol
        daVol = &nVol
    } else {
        *daVol += nVol
    }
    hisVol,ok := r.hisVolume[evn.Security]
    if !ok {
        hisVol = makeHisVolList()
        r.hisVolume[evn.Security] = hisVol
    }
    hisVol.increment(evn.Volume)
    tlVol, cnt := hisVol.getAverage()
    if cnt > 0 && float64(*daVol * cnt) > float64(1.5 * float64(tlVol)) {
        sr = fmt.Sprintf("D M N: %v has executed over 50%% of the average volume for '%v', the total volume %v, the average is %.2f",
             evn.Broker, evn.Security, *daVol, (float64(tlVol))/(float64(cnt)))
    }
    return
}

