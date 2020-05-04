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
    rules = append(rules,InitRov())
    rules = append(rules,InitRoe())
    rules = append(rules,InitRsfp())
    rules = append(rules,InitRap())
    rules = append(rules,InitRdmn())
    return rules
}


