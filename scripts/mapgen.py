from random import randint

high = [' ',',','.',':',';']
low = ['O','0']

x = 500 
y = 500

f = open("map.txt","w+")

for i in range(y):
    for j in range(x):
        k = randint(1,50)
        if k == 1:
            f.write(low[randint(0,len(low)-1)])
        else:
            f.write(high[randint(0,len(high)-1)])
    f.write('\n')

f.close()
