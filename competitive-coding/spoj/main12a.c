#include <stdio.h>

int main()
{
      int t;
      int i,k,j;
      int a[10000] = {0};
      int n;
      int sum;
      int ctr = 0;

      j = 4;
      a[1] = 1;
      a[2] = 1;
      a[3] = 2;
      a[4] = 3;

      for ( i = 3; i < 336; i++ ) {
            for ( k = 0; k < a[i]; k++) {
                  a[j++] = i;
                  //printf("%d %d\n", a[j-1], j);
            }
      }

      scanf("%d", &t);

      while(t--) {
            ctr++;
            scanf("%d", &n);
            sum =0;
            for ( i = 1; i < 100000; i++ ) {
                  sum = sum + a[i];
                  if ( sum  >= n) {
                        break;
                  }
            }
            printf("Case #%d: %d\n", ctr, i);
      }
      return 0;
}
