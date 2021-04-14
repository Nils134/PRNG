import random

random.seed(42)
while(1):   
    print("Start")
    with open('randomPipe', 'w') as f:
        print("Writing")
        for x in range(0, 1000):
            line = '%.12f' % random.random() + "\n"
            f.write(line)
    print("end writing")
    with open('emptyPipe', 'r') as f:
        print("Reading")
        temp = f.read()
        print("End Reading")