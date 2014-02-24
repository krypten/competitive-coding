def gcd ( a, b) :
	if a%b == 0:
		return b
	return gcd(b, a%b)

def lcm( a, b):
	d = gcd(a,b)
	l = a*b/d;
	x = l/a
	y = l/b
	return l,x,y

t = int(raw_input())
while (t):
	t -= 1
	string = []
	string = str(raw_input()).split();
	tmp1 = string[0]
	tmp2 = string[1]

	n = len(tmp1)
	m = len(tmp2)

	lc,x,y = lcm( n , m)

	tmp3 = tmp1*x;
	tmp4 = tmp2*y;

	if tmp3 == tmp4:
		print ("YES")
	else :
		print ("NO")
