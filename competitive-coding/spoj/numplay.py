import math
import sys
t = int(sys.stdin.readline())
while t:
    t -= 1
    a = int(sys.stdin.readline())
    if a == 0:
        print (0)
        continue
    p1 = 1
    p3 = 1
    p5 = 1
    p7 = 1
    a -= 1
    while (a):
        a -= 1
        p1,p3,p5,p7 = p3, p1+p7 ,p3+p7, p5
    print(p1+p3+p5+p7)
        
        
