def add(r):
    if r == 0:
        return "2"
    elif r == 1:
        return "3"
    elif r == 2:
        return "5"
    elif r == 3:
        return "7"

t = int(input())
while t:
    t -= 1
    var = ""
    n = int(input())
    n -= 1
    if n < 4:
        var = add(n)
        print (var)
        continue
    while n > 0:
        r=n&3;
        n=n>>2
        n -= 1
        var = str(add(r)) + var
        if (n < 4):
            var = str(add(n)) + var;
            break
    print (var)
