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

func ParseLine(line string)(en ev.Event,r bool){
    vs := ss.Split(line,"|")
    if len(vs) == 0 {
        return
    }
    /*for _,s := range vs {
        fmt.Println(s)
    }*/
    if vs[0] == "ORDER" || vs[0] == "EXECUTE" {
    if len(vs) != 10{
        return
    }
    oid,err := sc.Atoi(vs[1])
    if err != nil {
        return
    }
    dt,br := getDateTime(vs[2]+"T"+vs[3])
    if br == false {
            return
    }
    ib :=  "BUY" ==  vs[6]
    vol,_ := sc.Atoi(vs[8])
    pri := -1.0
    if vs[9] != "MKT" {
        tpri,err := sc.ParseFloat(vs[9],64)
        if err != nil {
            return
        }
        pri = tpri
    }
    if vs[0] == "EXECUTE" {
        en,r = ev.InitExecute(oid,&dt,vs[4],vs[5],ib,vs[7],vol,pri)
    } else {
        en,r = ev.InitOrder(oid,&dt,vs[4],vs[5],ib,vs[7],vol,pri)
    }
    } else if vs[0] == "PRICE" {
        dt,br := getDateTime(vs[1]+"T"+vs[2])
        if br == false {
            return
        }
        pri,err := sc.ParseFloat(vs[4],64)
        if err != nil {
            return
        }
        en,r = ev.InitPrice(&dt,vs[3],pri)
    }
    return 
}


