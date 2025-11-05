#!/usr/bin/python

import sys

while True:
    line = sys.stdin.readline()
    num = int(line,16)
    if(num < int("2ff",16)):
        sys.stdout.write("<2ff\n")
    else:
        sys.stdout.write(">=2ff\n")
    sys.stdout.flush()

