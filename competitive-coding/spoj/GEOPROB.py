import sys
s = sys.stdin
t = int(s.readline())
while ( t) :
    t = t - 1
    li = [];
    b,c,d = map(int ,s.readline().split())
    print(c-b+c-d)
