
from .rio import IOR
from .rem import EMR
from .rov import OVR
from .roe import OER
from .sfp import SFP
from .rap import APR
from .dmn import DMN



def initActions():
    rules = []
    rules.append(IOR())
    rules.append(EMR())
    rules.append(OVR())
    rules.append(OER())
    rules.append(SFP())
    rules.append(APR())
    rules.append(DMN())
    return rules
