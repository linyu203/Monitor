package rule

import (
    ev "events"
    "fmt"
)

type Rivo struct{
    ord map[int]int
}
func InitRivo()Rule{
    riv := Rivo{}
    riv.ord = make(map[int]int)
    return &riv
}
func (rivo *Rivo) CheckEvent(evn *ev.Event) string{
    if evn.EventType == ev.EVENT_ORDER {
	rivo.ord[evn.OrderId] = evn.OrderId
    } else if evn.EventType == ev.EVENT_EXECUTE {
	if _,ok := rivo.ord[evn.OrderId]; !ok {
	    return fmt.Sprintf("IVO: the order %v is not valid",evn.OrderId)
	}
    }
    return ""
}

