import random
import sys

random.seed(42)
while(1):   
    data = sys.stdin.readline()
    if (data != ""):
        for x in range(0, 100):
            line = '%.12f' % random.random() 
            print(line, flush=True)
    