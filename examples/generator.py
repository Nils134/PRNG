import random

random.seed(42)

afile = open("Random_python.txt", "w" )

for i in range(int(input('How many random numbers?: '))):
    line = str(random.random())
    afile.write(line)

afile.close()