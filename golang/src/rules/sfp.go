package rule

import (
    ev "events"
    "fmt"
    "time"
    lst "container/list"
)

type buyRcd struct{
    rmVol int
    price float64 
    dt time.Time
}

type Rsfp struct{
    buyOrder map[string]*lst.List
}
func InitRsfp()Rule{
    rsfp := Rsfp{}
    rsfp.buyOrder = make(map[string]*lst.List)
    return &rsfp
}
func getDate(tm *time.Time)time.Time{
    y,m,d := tm.Date()
    return time.Date(y,m,d,0,0,0,0,time.UTC);
}
func getDiffDays(tm1, tm2 *time.Time)int{
    return int(tm1.Sub(*tm2).Hours()/24)
}
func makeRcd(evn *ev.Event) *buyRcd{
    tdt := getDate(&evn.EventTime)
    return &buyRcd {
        rmVol: evn.Volume,
        price: evn.Price,
        dt:    tdt,
    }
}

func getKey(evn *ev.Event) string{
    return evn.Client + "|" + evn.Security
}

func (r *Rsfp) CheckEvent(evn *ev.Event) (sr string){
    if evn.EventType != ev.EVENT_EXECUTE {
        return
    }
    key := getKey(evn)
    plist, ok := r.buyOrder[key]
    if evn.IsBuy {
        if !ok {
            r.buyOrder[key] = lst.New()
            plist = r.buyOrder[key]
        }
        plist.PushBack(makeRcd(evn))
        return
    }
    if !ok {
        return
    }
    curVol := evn.Volume
    curPri := evn.Price
    curDate := getDate(&evn.EventTime)
    lo := "02Jan2006"
    for curl := plist.Front(); curl != nil && curVol > 0; {
        tbrcd := curl.Value
        pav,ok := tbrcd.(*buyRcd)
        if !ok {
            return
        }
        if len(sr) == 0 && pav.price < curPri && getDiffDays(&curDate, &pav.dt) < 30{
            sr = fmt.Sprintf("SFP: order %v Sold '%v' within 30 days Bought on %v at $%.2f sold on %v at $%.2f",
                 evn.Client, evn.Security, pav.dt.Format(lo), pav.price, curDate.Format(lo), curPri)
        }
        if(curVol >= pav.rmVol){
            curVol -= pav.rmVol
            plist.Remove(curl)
	    curl = plist.Front()
        } else {
            pav.rmVol -= curVol
            break
        }
    }
    return
}

