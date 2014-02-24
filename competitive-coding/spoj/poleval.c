#include <stdio.h>

int main()
{
      int i, j;
      int n;
      int k;
      int ctr = 0;
      int x;
      while (1) {
            int c[1024] = {0};
            ctr++;
            scanf("%d", &n);
            if ( n == -1) {
                  break;
            }
            for ( i = n; i >= 0; i--) {
                  scanf("%d", &c[i]);
            }
            scanf("%d", &k);
            printf("Case %d:\n", ctr);
            for ( j =0; j < k; j++) {
                  long long int sum;
                  sum = c[n];
                  scanf("%d", &x);
                  for ( i = n; i > 0; i--) {
                        sum = sum*x + c[i-1];
                  }
                  printf("%lld\n", sum);
            }
      }
      return 0;
}
