package event

import (
    tm "time"
)

type EVENT_TYPE uint8
const (
    _              =   iota
    EVENT_ORDER
    EVENT_EXECUTE
    EVENT_PRICE
)

type Event struct{
    EventType EVENT_TYPE
    OrderId int
    EventTime tm.Time
    Client string
    Broker string
    IsBuy bool
    Security string
    Volume int
    Price float64
}

func InitPrice(dt *tm.Time, sec string, pri float64) (Event,bool){
    return Event{
        EventType: EVENT_PRICE,
        EventTime: *dt,
        Security:  sec,
        Price:     pri,
    },true
}
func InitOrder(oid int, dt *tm.Time, cli , bro string, ib bool, sec string, vol int, pri float64) (Event,bool){
    return Event{
        EventType: EVENT_ORDER,
        OrderId:   oid,
        EventTime: *dt,
        Client:    cli,
        Broker:    bro,
        IsBuy:     ib,
        Security:  sec,
        Volume:    vol,
        Price:     pri,
    },true
}
func InitExecute(oid int, dt *tm.Time, cli , bro string, ib bool, sec string, vol int, pri float64) (Event,bool){
    return Event{
        EventType: EVENT_EXECUTE,
        OrderId:   oid,
        EventTime: *dt,
        Client:    cli,
        Broker:    bro,
        IsBuy:     ib,
        Security:  sec,
        Volume:    vol,
        Price:     pri,
    },true
}
