package rule

import (
    ev "events"
)

type Rule interface{
    CheckEvent(evn *ev.Event) string
}


func InitAllRules() []Rule{
    var rules []Rule
    //var riv Rule = &Rivo{}
    rules = append(rules,InitRivo())
    rules = append(rules,InitRme())



    return rules
}


