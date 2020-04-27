from event import Event

class SFP:
    def __init__(self):
        self.d_buyDict = dict()

    def check(self, evn):
        if evn.eventType != "EXECUTE":
            return None
        key = evn.client + "|" + evn.parsekey
        ss = ''
        if evn.isBuy:
            if key not in self.d_buyDict:
                self.d_buyDict[key] = list()
            self.d_buyDict[key].append([evn.price, evn.dateTime.date(), evn.volume])
        else:
            if key not in self.d_buyDict:
                return None
            ll = self.d_buyDict[key]
            curVol = evn.volume
            curDate = evn.dateTime.date()
            curPrice = evn.price
            while curVol > 0 && ll:
                l0 = ll[0]
                if ss == '' and l0[0] < curPrice and curDate - l0[1] < 30:
                    "SFP: order CLIENT1 Sold 'SECURITY' within 30 days Bought on 01MAR2020 at $100.10 sold on 20MAR2020 at $100.20"
                    ss = "SFP: order {} Sold '{}' within 30 days Bought on {} at ${:.2f} sold on {} at ${:.2f}"
                    ss = ss.format(evn.client, evn.parsekey, l0[1].strftime("%d%b%Y").upper(), l0[0],
                                   curDate.strftime("%d%b%Y").upper(), curPrice)
                if curVol >= l0[2]:
                    curVol -= l0[2]
                    ll.remove(0)
                else:
                    l0[2] -= curVol
                    ll[0] = l0
                    break
                    
           self.d_buyDict[key] = ll
           
        return ss
