import sys

def mod_exp(a, b):
    """return a**b % q"""
    q = 10000007
    val = 1
    mult = a
    while b > 0:
        odd = b & 1 # bitwise and
        if odd == 1:
            val = (val * mult) % q
            b -= 1
        if b == 0:
            break
        mult = (mult * mult) % q
        b = b >> 1 # bitwise divide by 2
    return val




while True:
    a,b = map(int , sys.stdin.readline().split())
    if a == 0 and b == 0:
        break
    print ((mod_exp(a,b) + 2*mod_exp(a-1,b) + mod_exp(a,a) + 2*mod_exp(a-1,a-1))%10000007)


