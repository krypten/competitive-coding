import re

t = int (raw_input())
case = 1
while case <= t:
	string = re.findall("[a-zA-Z0-9][a-zA-Z0-9._]{4,}@[a-zA-Z0-9]+\.(?:com|edu|org|co\.in)", raw_input())
	l = len(string)
	print ("Case #" + str(case) + ": " + str(l))
	for i in range (l) : print string[i]
	case = case + 1
