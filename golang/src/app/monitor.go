package main

import (
    rl "rules"
    ac "actions"
)
type Monitor struct {
    d_rules []rl.Rule
    d_actions []ac.Action
}

func (m*Monitor)Init(){
    m.d_actions = ac.InitAllActions()
    m.d_rules = rl.InitAllRules()
}

func (m*Monitor)MparseLine(line string)string{
    event,rb := ParseLine(line)
    if rb == false {
        return "Parse line failed"
    }
    for _, rule := range m.d_rules {
        ts := rule.CheckEvent(&event)
        if len(ts) == 0 {
            continue
        }
        for _,act := range m.d_actions {
            act.TakeAction(ts)
        }
    }
    return ""
}

