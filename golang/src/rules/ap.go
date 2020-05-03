package rule

import (
    ev "events"
    "fmt"
)

type Rap struct{
    marketPrice map[string]float64
}
func InitRap()Rule{
    rap := Rap{}
    rap.marketPrice = make(map[string]float64)
    return &rap
}
func (r *Rap) CheckEvent(evn *ev.Event) string{
    if evn.EventType == ev.EVENT_PRICE {
        r.marketPrice[evn.Security] = evn.Price
    } else if evn.EventType == ev.EVENT_EXECUTE {
        if pri,ok := r.marketPrice[evn.Security]; ok {
            if pri *2.0 < evn.Price || pri > evn.Price * 2.0 {
                return fmt.Sprintf("A P: %v has executed $%.2f for '%v', while the market price is $%.2f",
                       evn.Broker, evn.Price, evn.Security, pri)
            }
        }
    }
    return ""
}
