t = input()
while(t) :
	t -= 1
	x , k = [int(x) for x in raw_input().split()]
	y = x/(k-1)
	y = int (y)
	if x%(k-1) == 0 :
		y = y-1
	print(x+y)


