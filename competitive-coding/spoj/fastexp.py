import sys
t =int(sys.stdin.readline())
while(1):
    if t == 0:
        break
    t -= 1
    n = int(sys.stdin.readline())
    tmp = 1
    tmp = (2**(n+1) - 1)%1298074214633706835075030044377087
    sys.stdout.write(str(tmp))
    sys.stdout.write("\n") 
