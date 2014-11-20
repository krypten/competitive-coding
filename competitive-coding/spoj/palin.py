def inc(left):
	leftlist=list(left)
	last = len(left)-1
	while leftlist[last]=='9':
		leftlist[last]='0'
		last-=1
		if (last == -1):
			leftlist = list('0') + leftlist
			last = 0;
			break;

	leftlist[last] = str(int(leftlist[last])+1)
	return "".join(leftlist)

t = int(raw_input())
while (t):
	t -= 1
	n = raw_input()
	ans = ""
	length = len(n)
	if (length%2 == 0):
			first = n[0:length//2]
			ans = first + first[::-1]
			if (ans <= n):
				temp = inc(first)
				if (len(temp) > len(first)):
					ans = temp[0:-1] + temp[::-1]
				else :
					ans = temp + temp[::-1]
	else:
		first = n[0:length//2]
		ans = first + n[length//2] + first[::-1];
		if(ans <= n):     
			first = inc(first + n[length//2])
			if (ans == '9'):
				ans = "11";
			else:
				ans = first + first[0:-1][::-1]

	print (ans)