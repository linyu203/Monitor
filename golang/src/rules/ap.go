package rule

import (
    ev "events"
    "fmt"
)

type Rap struct{
    marketPrice map[string]flout64
}
func InitRap()Rule{
    rap := Rap{}
    rap.marketPrice = make(map[string]flout64)
    return &rap
}
func (r *Rap) CheckEvent(evn *ev.Event) string{
    if evn.EventType == ev.EVENT_ORDER {
        r.marketPrice[evn.Security] = evn.Price
    } else if evn.EventType == ev.EVENT_EXECUTE {
        if pri,ok := r.marketPrice[evn.Security]; ok {
            if pri *2.0 < evn.Price || pri > evn.Price * 2.0 {
                return fmt.Sprintf("A P: %v has executed $%v for '%v', while the market price is $%v",
                       evn.Broker, evn.Price, evn.Security, pri)
            }
        }
    }
    return ""
}