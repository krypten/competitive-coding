while True:
    d, n = input().split()
    n = int(n)
    d = int(d)
    if (n == 0 and d == 0):
        break
    print (d**n)
