
class Event:
    def __init__(self, eventType, dt, psk, pri, oid=0, client='', broker='', isBuy=False, vol=0):
        self.__et = eventType
        self.__dt = dt
        self.__psk = psk
        self.__pri = pri
        self.__oid = oid
        self.__cli = client
        self.__bro = broker
        self.__isb = isBuy
        self.__vol = vol
        
    @property
    def eventType(self):
        return self.__et
        
    @property        
    def dateTime(self):
        return self.__dt
        
    @property
    def parsekey(self):
        return self.__psk
        
    @property
    def price(self):
        return self.__pri

    @property
    def orderId(self):
        return self.__oid

    @property
    def client(self):
        return self.__cli

    @property
    def broker(self):
        return self.__bro

    @property
    def isBuy(self):
        return self.__isb
        
    @property
    def volume(self):
        return self.__vol

