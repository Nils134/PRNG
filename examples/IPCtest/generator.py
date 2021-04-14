import random

random.seed(42)
while(1):   
    with open('pipe', 'w') as f:
        f.write(str(random.random()))
    with open('pipe', 'r') as f:
        temp = f.read()