from numpy import random

random.seed(42)

afile = open("Random_python_numpy.txt", "w" )

for i in range(int(input('How many random numbers?: '))):
    line = str(random.random())
    afile.write(line)

afile.close()