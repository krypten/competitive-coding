import math
def gcd(a,b):
	if (a%b == 0):
		return b;
	return gcd(b, a%b);

t = int(raw_input())
while t: 
	n = raw_input()
	flag = False
	num = 0;
	cnt = 0;
	for ch in n:
		if (ch != '.'):
			num = num * 10 + int(ch)
		if (flag):
			cnt+=1
		if (ch == '.'):
			flag = True;
		
	power = 10 ** cnt;

	#print num
	#print power
	if flag:
		print power/gcd(num,power)
	else:
		print 1
	t-= 1