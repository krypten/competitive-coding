def RepresentsInt(s):
    try: 
        int(s)
        return True
    except ValueError:
        return False
t = int(input());
while t:
	t -= 1
	s = input();
	n = input().split(" ");
	if (not RepresentsInt(n[0])):
		print (str(int (n[4]) - int(n[2])) + " + " + n[2] + " = " + n[4])
	if (not RepresentsInt(n[2])):
		print (n[0] + " + " + str(int(n[4]) -int(n[0])) + " = " + n[4])
	if (not RepresentsInt(n[4])):
		print (n[0] + " + " + n[2] + " = " + str(int(n[0]) + int(n[2])))
