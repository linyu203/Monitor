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
func (rivo *Rme) CheckEvent(evn *ev.Event) string{
    if evn.EventType == ev.EVENT_ORDER {
	rivo.ord[evn.OrderId] = evn
    } else if evn.EventType == ev.EVENT_EXECUTE {
	if pev,ok := rivo.ord[evn.OrderId]; ok {
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
		return fmt.Sprintf("EM order %v jsdkjfsdlfj %v", evn.OrderId, tmp)

	    }
        }
    }
    return ""
}

