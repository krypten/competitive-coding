def add(r):
    if r == 0:
        return "5"
    else :
        return "6"

t = int(input())
while t:
    t -= 1
    var = ""
    n = int(input())
    n -= 1
    if n < 2:
        var = add(n)
        print (var)
        continue
    while n > 0:
        r=n&1;
        n=n>>1
        n -= 1
        var = str(add(r)) + var
        if (n < 2):
            var = str(add(n)) + var;
            break
    print (var)
