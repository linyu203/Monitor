
from datetime import datetime as dt
from event import Event

def parseString(line):
    fields = line.split('|')
    if not fields:
        return None
    evntp = fields[0]
    if evntp is "PRICE":
        if len(fields) != 5:
            return None
        stringdt = fields[1] + "|" + fields[2]
        curdt = dt.strptime(stringdt, "%Y%m%d|%H:%M:%S")
        psk = fields[3]
        price = float(fields[4])
        return Event(evntp, curdt, psk, price)
        
    elif evntp is "ORDER" or "EXECUTE":
        if len(fields) != 10:
            return None
        oid = int(fields[1])
        stringdt = fields[2] + "|" + fields[3]
        curdt = dt.strptime(stringdt, "%Y%m%d|%H:%M:%S")
        client = fields[4]
        broker = fields[5]
        isBuy = fields[6] == "BUY"
        psk = fields[7]
        vol = int(fields[8])
        if fields[9] is "MKT":
            price = -1.0
        else:
            price = float(fields[9])
        return Event(evntp, curdt, psk, price, oid, client, broker, isBuy, vol)
        
    return None