while True:
        try:
                l = []
                n = int(input())
                s = str(input())
                for i in range(n):
                        x = str(input());
                        s = s.replace(x,"");
                if len(s) == 0:
                        print ("0")
                else:
                        print (s)
        except:
                break;
