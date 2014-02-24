//use recursion
#include <stdio.h>

int main()
{
      int n;
      int t;
      int ctr;
      scanf("%d", &t);
      while( t--) {
            scanf("%d", &n);
            ctr = 0;
            while(n > 0) {
                  ctr++;
                  if(n == 2) {
                        ctr++;
                        break;
                  }
                  if( n%2 == 0) n = n>>1;
                  else n = (n+1)>>1;
            }
            printf("%d\n", ctr);
      }
      return 0;
}

