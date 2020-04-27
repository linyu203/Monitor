from event import Event


class HisVolum:
    def __init__(self):
        self.d_sum = 0
        self.d_curVol = 0
        self.d_hisVol = list()

    def increment(self, vol):
        self.d_curVol += vol

    def update(self):
        if self.d_curVol == 0:
            return False
        self.d_sum += self.d_curVol
        self.d_hisVol.append(self.d_curVol)
        self.d_curVol = 0
        if len(self.d_hisVol) == 5:
            self.d_sum -= self.d_hisVol[0]
            self.d_hisVol.remove(0)
        return true;

    def getSumAndCnt(self):
        return self.d_sum, len(self.d_hisVol)

        
        
class DMN:
    def __init__(self):
        self.d_curVolDict = dict()
        self.d_curDate = -1
        self.d_hisVolDict = dict()

    def updateHis(self, curDate):
        if curDate == self.d_curDate:
            return
        self.d_curDate = curDate
        self.d_curVolDict.clear()
        for key,val in self.d_hisVolDict.items():
            if val.update():
                self.d_hisVolDict[key] = val
        
    def check(self, evn):
        if evn.eventType != "EXECUTE":
            return None

        curDate = evn.dateTime.date()
        updateHis(curDate)
        key = evn.broker + "|" + evn.parsekey
        tVol = self.d_curVolDict[key] += evn.volume
        self.d_hisVolDict[evn.parsekey].increment(evn.volume)
        sum, cnt = self.d_hisVolDict[evn.parsekey].getSumAndCnt()
        if cnt>0 and cnt * tVol > 1.5 * sum:
            ss = "D M N: {} has executed over 50% of the average volume for '{}', the total volume {}, the average is {:.2f}"
            ss = ss.format(evn.broker, evn.parsekey, tVol, sum/cnt)
            return ss
            
        return None
