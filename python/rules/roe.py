from event import Event

class OER:
    def __init__(self):
        self.d_orderDict = dict()

    def check(self, evn):
        if evn.eventType == "ORDER":
            self.d_orderDict[evn.orderId] = [evn.dateTime, evn.price]
            
        elif evn.eventType == "EXECUTE":
            if evn.orderId not in self.d_orderDict:
                return None

            odt = self.d_orderDict[evn.orderId][0]
            isMarket = self.d_orderDict[evn.orderId][1] < 0.0
            edt = evn.dateTime

            ss = ""
            
            if isMarket:
                if odt.date() != edt.date() or (edt-odt).total_seconds() >= 300:
                    ss = "ODE: Market order expired, order was placed on {} at {} executed on {} at {}"

            else:
                if odt.date() != edt.date():
                    ss = "ODE: Limit order expired, order was placed on {} at {} executed on {} at {}"

            if ss:
                return ss.format(odt.strftime("%d%b%Y").upper(), odt.strftime("%H:%M:%S"),
                                 edt.strftime("%d%b%Y").upper(), edt.strftime("%H:%M:%S"))
            
        return None
