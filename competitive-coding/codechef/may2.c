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
            printf("0\n");
            continue;
      }

      for ( i = 0; i<n; i++) {
            scanf("%lld", &arr[i]);
      }
      while (n != 1) {
            for(i = 0; i<n-1; i++){
                  for(j = i+1; j < n; j++){
                        arr[i-1] = gcd(arr[i], arr[j]);


                  }
            }
      }

      printf("%lld\n", arr[n-1]);
      }
      return 0;
}
