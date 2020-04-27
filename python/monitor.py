

from rules.rule import initRules
from actions.action import initActions
from parse import parseString


class Monitor:
    def __init__(self):
        self.d_rules = initRules()
        self.d_actsions = initActions()

    def parse(self, line):
        event = parseString(line)
        if not event:
            throw Exception("parse string failed")
            
        for r in self.d_rules:
            s = r.check(event)
            if not s:
                continue
            for act in self.d_actions:
                act.tackAction(s)

