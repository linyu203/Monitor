from event import Event

class APR:
    def __init__(self):
        self.d_orderDict = dict()

    def check(self, evn):
        if evn.eventType == "PRICE":
            self.d_orderDict[evn.parsekey] = evn.price
            
        elif evn.eventType == "EXECUTE":
            if evn.parsekey not in self.d_orderDict:
                return None
            mktPrice = self.d_orderDict[evn.parsekey]
            if mktPrice*2.0 < evn.price or evn.price*2.0 < mktPrice:
                ss = "A P: {} has executed ${:.2f} for '{}', while the market price is ${:.2f}"
                return ss.format(evn.broker, evn.price, evn.parsekey, mktPrice)
            
        return None
