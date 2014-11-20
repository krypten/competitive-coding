t = int(raw_input())
while t:
	t -= 1
	st = str(raw_input())

	if st == st[::-1]:
		print ("YES")
	else : 
		print ("NO")
