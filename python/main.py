#!/usr/bin/env python3.7

import sys

from monitor import Monitor

def main(argv):
    if len(argv) != 1:
        print("Input format not valid!")
        return
        

    m = Monitor()
    with open(argv[0], 'r') as f:
        lines = f.read()
        lines = lines.split('\n')
        for line in lines:
            if not line:
                break
            try:
                m.parse(line)
            except Exception as e:
                print("skip line with error: {}".format(repr(e)))
                #return

if __name__ == "__main__":
    main(sys.argv[1:])

