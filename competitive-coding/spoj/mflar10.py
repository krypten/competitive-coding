while True:
	text = raw_input();
	if not text:
		continue
	if text[0] == '*':
		break;
	text = text.split(" ");

	#print (text)
	i = 0
	while (not text[i]):
		i+=1
	c = text[i];
	flag = True
	for t in text:
		if t and not (t[0].lower() == c[0].lower()):
			print ('N')
			flag = False
			break;
	if flag:
		print ('Y')