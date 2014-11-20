def gcd(a,b):
	while (b != 0):
		c = a
		a = b
		b = c%b
	return a
t = int(input())
while (t):
	t -= 1
	x = input().split(" ")
	a = int(x[0])
	b = int(x[1])
	print (gcd(a,b))