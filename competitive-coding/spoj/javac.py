while True:
    try:
        s = raw_input();
    except:
        break;

    flagc = True
    flagj = True
    if (s[0].isupper() or s[0] == '_'):
        flagc = False
        flagj = False
    for ch in s:
        if (not ch.isalpha()):
            flagj = False;
        elif (ch.isupper()):
            flagc = False;
    if (not flagc and not flagj):
        print("Error!")
        continue;
    ans = ""
    if flagc and flagj:
        ans = s;
    elif flagc:
        test = s.split("_")
        ans = test[0];
        i = 1;
        while i < len(test):
            if test[i] == "":
                ans = "Error!"
                break;
            ans = ans + test[i].capitalize()
            i += 1
    elif flagj:
        for ch in s:
            if ch.isupper():
                ans += '_'
            ans += ch.lower();
    print (ans)