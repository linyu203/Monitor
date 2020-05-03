package rule

import (
    ev "events"
    "fmt"
)

type Rme struct{
    ord map[int]*ev.Event
}
func InitRme()Rule{
    riv := Rme{}
    riv.ord = make(map[int]*ev.Event)
    return &riv
}
func (r *Rme) CheckEvent(evn *ev.Event) string{
    if evn.EventType == ev.EVENT_ORDER {
        r.ord[evn.OrderId] = evn
    } else if evn.EventType == ev.EVENT_EXECUTE {
        if pev,ok := r.ord[evn.OrderId]; ok {
            var tmp string
            if evn.Client != pev.Client {
                tmp += " client"
            }
            if evn.Broker != pev.Broker {
                tmp += " broker"
            }
            if evn.IsBuy != pev.IsBuy {
                tmp += " type"
            }
            if evn.Security != pev.Security {
                tmp += " parsekey"
            }
            if evn.Volume > pev.Volume {
                tmp += " volume"
            }
            if pev.Price >= 0.0 && pev.Price != evn.Price {
                tmp += " price"
            }
            if len(tmp) > 0 {
                return fmt.Sprintf("EM: order %v is not matched with the order, mismatched fields:%v", evn.OrderId, tmp)
            }
        }
    }
    return ""
}

