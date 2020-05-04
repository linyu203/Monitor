package action

import (
    "fmt"
)

type Action interface{
    TakeAction(msg string)
}

type fmtPrintAction struct{
}
func (fpa * fmtPrintAction) TakeAction(msg string){
    fmt.Println(msg)
}

func InitAllActions() []Action{
    var actions []Action
    var fpa Action = &fmtPrintAction{}
    actions = append(actions, fpa)

    return actions
}
