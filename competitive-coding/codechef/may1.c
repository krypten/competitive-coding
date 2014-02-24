#include <stdio.h>
#define SIZ 1024

long long int gcd(long long int a, long long int b)
{
      if ( a%b == 0 )
            return b;
      return gcd(b, a%b);
}

int main()
{
      int i;
      int tc;
      int n;
      long long int arr[SIZ];

      scanf("%d", &tc);

      while (tc--) {

      scanf("%d", &n);

      if (n == 1) {
            scanf("%lld", &arr[0]);
            printf("%lld\n", arr[0]);
            continue;
      }

      for ( i = 0; i<n; i++) {
            scanf("%lld", &arr[i]);
            if(i != 0) {
                  arr[i] = gcd(arr[i-1], arr[i]);
            }
      }

      printf("%lld\n", arr[n-1]);
      }
      return 0;
}
