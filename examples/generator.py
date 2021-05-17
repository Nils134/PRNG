import random
import sys

random.seed(42)
while(1):   
    data = sys.stdin.readline()
    if (data != ""):
        for x in range(0, 10000):
            line = ""
            for i in range(0, 100):
                temp = '%.12f' % random.random() 
                line += str(temp) + "\n"
            print(line,end='', flush=True)
    