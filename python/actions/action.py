


class PrintAction:
    def __init__(self):
        pass

    def tackAction(self, args):
        print(args)


def initActions():
    actions = []
    actions.append(PrintAction())
    return actions

