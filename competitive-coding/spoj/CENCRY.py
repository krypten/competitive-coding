import sys
t=int(input())
vow = {'a':1,'e':2,'i':3,'o':4,'u':5}
vow2 = ['a','e','i','o','u']
alp = {'b' : 1,'c': 2,'d': 3,'f': 4,'g': 5,'h': 6,'j': 7,'k': 8,'l':9,'m':10,'n': 11,'p':12,'q': 13,'r': 14,'s': 15,'t': 16,'v': 17,'w': 18,'x': 19,'y': 20,'z': 21}
alp2 = ['b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z']

while t:
    t-=1 ;
    arr = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    enc = ""
    string = sys.stdin.readline()
    i = 0
    l = len(string);
    while l > 1:
        l -= 1
        tp = ord(string[i]) - 97
        if string[i] in vow:
            tmp = vow[string[i]]-1 + arr[tp]*5
            enc = enc + str(alp2[tmp%21])
            arr[tp] += 1
        else :
            tmp = alp[string[i]]-1 + arr[tp]*21
            enc = enc + str(vow2[tmp%5])
            arr[tp] += 1
        i += 1
    print (enc)

