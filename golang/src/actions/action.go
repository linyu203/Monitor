package action

type Action interface{
    TakeAction(msg string)
}

func InitAllActions() []Action{
    var actions []Action
    actions = append(actions, &FmtPrintAction{})

    return actions
}
