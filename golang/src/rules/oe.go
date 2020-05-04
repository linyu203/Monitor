package rule

import (
    ev "events"
    "fmt"
    //"time"
    ss "strings"
)

type Roe struct{
    ord map[int]*ev.Event
}
func InitRoe()Rule{
    riv := Roe{}
    riv.ord = make(map[int]*ev.Event)
    return &riv
}
func (r *Roe) CheckEvent(evn *ev.Event) string{
    if evn.EventType == ev.EVENT_ORDER {
        r.ord[evn.OrderId] = evn
    } else if evn.EventType == ev.EVENT_EXECUTE {
        pev,ok := r.ord[evn.OrderId]
        if !ok {
            return ""
        }
        var isMkt bool = pev.Price <0.0
        ot := &pev.EventTime
        et := &evn.EventTime
        y1,m1,d1 := ot.Date()
        y2,m2,d2 := et.Date()
        lod := "02Jan2006"
	lot := "15:04:05"
        if !(y1 == y2 && m1 == m2 && d1 == d2) ||
           (isMkt && et.Sub(*ot).Seconds()>=300) {
            if (isMkt){
                return fmt.Sprintf("ODE: Market order expired, order was placed on %v at %v executed on %v at %v",
                       ss.ToUpper(ot.Format(lod)), ot.Format(lot), ss.ToUpper(et.Format(lod)), et.Format(lot))
            } else {
                return fmt.Sprintf("ODE: Limit order expired, order was placed on %v at %v executed on %v at %v",
                       ss.ToUpper(ot.Format(lod)), ot.Format(lot), ss.ToUpper(et.Format(lod)), et.Format(lot))
            }
        }
    }
    return ""
}
