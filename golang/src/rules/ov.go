package rule

import (
    ev "events"
    "fmt"
)

type Rov struct{
    ord map[int]int
}
func InitRov()Rule{
    riv := Rov{}
    riv.ord = make(map[int]int)
    return &riv
}
func (r *Rov) CheckEvent(evn *ev.Event) string{
    if evn.EventType == ev.EVENT_ORDER {
        r.ord[evn.OrderId] = evn.Volume
    } else if evn.EventType == ev.EVENT_EXECUTE {
        if pev,ok := r.ord[evn.OrderId]; ok {
            pev -= evn.Volume
            r.ord[evn.OrderId] = pev;
            if pev < 0 {
                return fmt.Sprintf("OSE: order %v has been executed oversized by %v", evn.OrderId, evn.Broker)
            }
        }
    }
    return ""
}

