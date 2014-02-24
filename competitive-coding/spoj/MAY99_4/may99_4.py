import sys

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        return None  # modular inverse does not exist
    else:
        return x % m

tp = 1;	

string = sys.stdin.readline()
l1 = []
l1 = string.split();
n = int(l1[0]);
r = int(l1[1]);

if(n < r) :
	print(-1);
elif n == r :
        print(1);
else :
	n = n-r;
	tp2 = 1;
	for i in range(1, r+1) :
		tp = tp*(n-i+1) % 10000007;
		tp2 =tp2*(i)%10000007;
	ans = tp * modinv(tp2, 10000007)%10000007
	print (ans)
