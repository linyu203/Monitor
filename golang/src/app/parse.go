package main

import (
    tm "time"
    ev "events"
    ss "strings"
    sc "strconv"
    //"fmt"
)

func getDateTime(line string)(tm.Time,bool){
    //line = line[:4] +  "-" + line[4:6] + "-" + line[6:]
    t,err := tm.Parse("20060102T15:04:05", line)
    //fmt.Println(t,line)
    if err != nil{
        return t,false
    }
    return t,true
}

func ParseLine(line string)(ev.Event,bool){
    vs := ss.Split(line,"|")
    if len(vs) == 0 {
        return ev.Event{},false
    }
    /*for _,s := range vs {
        fmt.Println(s)
    }*/
    if vs[0] == "ORDER" || vs[0] == "EXECUTE" {
    if len(vs) != 10{
        return ev.Event{},false
    }
    oid,err := sc.Atoi(vs[1])
    if err != nil {
        return ev.Event{},false
    }
    dt,br := getDateTime(vs[2]+"T"+vs[3])
    if br == false {
            return ev.Event{},false
    }
    ib :=  "BUY" ==  vs[6]
    vol,_ := sc.Atoi(vs[8])
    pri := -1.0
    if vs[9] != "MKT" {
        tpri,err := sc.ParseFloat(vs[9],64)
        if err != nil {
            return ev.Event{},false
        }
        pri = tpri
    }
    if vs[0] == "EXECUTE" {
        return ev.InitExecute(oid,&dt,vs[4],vs[5],ib,vs[7],vol,pri)
    } else {
        return ev.InitOrder(oid,&dt,vs[4],vs[5],ib,vs[7],vol,pri)
    }
    } else if vs[0] == "PRICE" {
        dt,br := getDateTime(vs[1]+"|"+vs[2])
        if br == false {
            return ev.Event{},false
        }
        pri,err := sc.ParseFloat(vs[4],64)
        if err != nil {
            return ev.Event{},false
        }
        return ev.InitPrice(&dt,vs[3],pri)
    }
    return ev.Event{},false
}


