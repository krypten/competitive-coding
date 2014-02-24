def add( n):
    if n == 0 :
        return "m";
    elif n == 1 :
        return "a";
    elif n == 2 :
        return "n";
    elif n == 3 :
        return "k";
    elif n == 4 :
        return "u";
    elif n == 5 :
        return "m";

t = int(input())
while t:
    t -= 1
    var = ""
    n = int(input())
    n -= 1
    if n < 5:
        var = add(n)
        print (var)
        continue
    while n > 0:
        r=n%5
        n=n//5

        # TODO : correct for 26 27 28 showing uum not um
        #if r == 0:
        n -= 1
        var = str(add(r)) + var
        if (n < 5):
            var = str(add(n)) + var;
            break
    print (var)
