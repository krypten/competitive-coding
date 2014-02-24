#include <stdio.h>
#include <stdlib.h>

long long int gcd(long long int a, long long int b)
{
      if ( a%b == 0 )
            return b;
      return gcd(b, a%b);
}

int main()
{
      int tc;
      long long int i;
      long long int n;
      long long int * arr;
      unsigned long long int ctr;

      scanf("%d", &tc);

      while (tc--) {

      scanf("%lld", &n);
      arr = (long long int ) malloc((n+1) * sizeof(long long int));

      if (n == 1) {
            printf("1\n");
            continue;
      }

      for ( i = 0; i<n; i++) {
            scanf("%lld", &arr[i]);
            if (i != 0) {
                 ctr *= (arr[i] ^ arr[i-1]);
            }
      }

      if (ctr == 0) {
            printf("%lld\n", n*n);
      }
      }
      return 0;
}
