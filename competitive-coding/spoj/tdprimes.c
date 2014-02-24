#include <stdio.h>
#include <stdlib.h>

const int MAX = 1000000000;
const int LMT = 100000;
const int LEN = 57615000;

int flag[15624880];
int prime[57615000];

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve()
{
      register int i,j,k;
      for(i = 3; i < LMT;i+=2) {
            if(!ifc(i))
            for(j = i*i, k = i<<1; j <MAX; j+= k)
                  isc(j);
      }
      prime[1] = 2;
      for(i = 3,j = 2; i <MAX && j<= LEN; i+=2)
            if(!ifc(i))
                  prime[j++] = i;
}

int main() {
      register int i= 1;
      sieve();

      for( ;i< 57615000; i+=100) {
            printf("%d\n", prime[i]);
      }
      return 0;
}
