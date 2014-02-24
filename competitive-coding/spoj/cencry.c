/*
//import sys
//t=int(input())
vow = {'a':1,'e':2,'i':3,'o':4,'u':5}
vow2 = ['a','e','i','o','u']
alp = {'b' : 1,'c': 2,'d': 3,'f': 4,'g': 5,'h': 6,'j': 7,'k': 8,'l':9,'m':10,'n': 11,'p':12,'q': 13,'r': 14,'s': 15,'t': 16,'v': 17,'w': 18,'x': 19,'y': 20,'z': 21}
alp2 = ['b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z']

//while t:
    //t-=1 ;
    //arr = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    //enc = ""
    //string = sys.stdin.readline()
    //i = 0
    //while string[i] != '\0':
        //tp = ord(string[i]) - 97
        //if string[i] in vow:
            tmp = vow[string[i]]-1 + arr[tp]*5
            enc = enc + str(alp2[tmp%21])
            arr[tp] += 1
        //else :
            tmp = alp[string[i]]-1 + arr[tp]*21
            enc = enc + str(vow2[tmp%5])
            arr[tp] += 1
    //print (enc)
*/
#include <string.h>
#include <stdio.h>

int vow[5]={1,5,9,15,21};
int alp[21]={2,3,4,6,7,8,10,11,12,13,14,16,17,18,19,20,22,23,24,25,26};
int hash_vow[]={1,0,0,0,2,0,0,0,3,0,0,0,0,0,4,0,0,0,0,0,5,0,0,0,0,0};
int hash_alp[]={0,1,2,3,0,4,5,6,0,7,8,9,10,11,0,12,13,14,15,16,0,17,18,19,20,21};

int main()
{
      int t;
      int i;
      int l;
      int tmp, len;
      char c;
      char str[100008];
      char enc[100008];
      int arr[27];
      scanf("%d", &t);
      while(t--) {
            scanf("%s", str);
            memset(arr, 0, sizeof(arr));
            i = 0;
            len = 0;
            l = strlen(str);
            while (l--) {
                  c = str[i]-97;
                  if (hash_vow[c] != 0) {
                        tmp = hash_vow[c]-1 + arr[c]*5;
                        enc[len++] = (char)(alp[tmp%21] + 96);
                        arr[c] += 1;
                  } else {
                        tmp = hash_alp[c]-1 + arr[c]*21;
                        enc[len++] = (vow[tmp%5] + 96);
                        arr[c] += 1;
                  }
                  i++;
            }
            enc[len] = '\0';
            printf("%s\n", enc);
      }
      return 0;
}
