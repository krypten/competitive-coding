#include <stdio.h>

int main()
{
      long long int t;
      long long int i;
      long long int m;
      long long int n;
      long long int k;
      long long int ans;
      long long int tmp;

      scanf("%lld", &t);

      for( i = 0; i < t;i++) {
            ans = 0;
            scanf("%lld %lld %lld", &m , &n , &k);
            tmp = n - 1;
            while (tmp > 0) {
                  tmp = tmp>>1;
                  ans++;
            }
            tmp = m - 1;
            while (tmp > 0) {
                  tmp = tmp>>1;
                  ans++;
            }
            tmp = k - 1;
            while (tmp > 0) {
                  tmp = tmp>>1;
                  ans++;
            }
            printf("Case #%lld: %lld %lld\n", i+1, n*m*k -1, ans);
      }
      return 0;
}
