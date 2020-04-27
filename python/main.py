#!/usr/bin/env python3.7

import sys

from monitor import Monitor

def main(argv):
    if len(argv) != 1:
        print("Input format not valid!")
        return
        

    m = Monitor()
    with open(argv[1], 'r') as f:
        lines = f.read()
        for i in lines:
            try:
                m.parse(i)
            except Exception as e:
                print("skip line with error: {}".format(repr(e)))

if __name__ == "__main__":
    main(sys.argv[1:])

