from event import Event

class EMR:
    def __init__(self):
        self.d_orderDict = dict()

    def check(self, evn):
        if evn.eventType == "ORDER":
            self.d_orderDict[evn.orderId] = evn
            
        elif evn.eventType == "EXECUTE":
            if evn.orderId not in self.d_orderDict:
                return None
            oEvent = self.d_orderDict[evn.orderId]
            fields = ""
            if oEvent.client != evn.client:
                fields += " client"
            if oEvent.broker != evn.broker:
                fields += " broker"
            if oEvent.isBuy != evn.isBuy:
                fields += " type"
            if oEvent.parsekey != evn.parsekey:
                fields += " parsekey"
            if oEvent.volume < evn.volume:
                fields += " volume"
            if oEvent.price >= 0 and oEvent.price != evn.price:
                fields += " price"
            if fields:
                return "EM: order {} is not matched with the order, mismatched fields: {}".format(evn.orderId, fields)
            
        return None