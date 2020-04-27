from event import Event

class IOR:
    def __init__(self):
        self.d_orderSet = set()

    def check(self, evn):
        if evn.eventType == "ORDER":
            self.d_orderSet.add(evn.orderId)
        elif evn.eventType == "EXECUTE":
            if evn.orderId not in self.d_orderSet:
                return "I O: order {} is not valid".format(evn.orderId)
                
        return None