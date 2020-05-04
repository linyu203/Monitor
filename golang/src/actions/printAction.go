package action

import (
    "fmt"
)

type FmtPrintAction struct{}

func (fpa * FmtPrintAction) TakeAction(msg string){
    fmt.Println(msg)
}

