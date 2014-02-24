t = int(input())

while (t != 0) :
    t = t - 1
    a = int(input())
    b = int(input())
    m = a;
    if ( b == 0):
        print ("1")
        continue
    if ( a == 1 or a == 0 or b == 1):
        print (a)
        continue
    for i in range(1, b):
        m = (m*a) % 10
        if m == 0:
            break
        print (m)
