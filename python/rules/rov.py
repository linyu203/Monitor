from event import Event

class OVR:
    def __init__(self):
        self.d_orderDict = dict()

    def check(self, evn):
        if evn.eventType == "ORDER":
            self.d_orderDict[evn.orderId] = evn.volume
            
        elif evn.eventType == "EXECUTE":
            if evn.orderId not in self.d_orderDict:
                return None
            rmVolume = self.d_orderDict[evn.orderId]
            rmVolume -= evn.volume
            self.d_orderDict[evn.orderId] = rmVolume
            if rmVolume < 0:
                return "OSE: order {} has been executed oversized by {}".format(evn.orderId, evn.broker)
            
        return None