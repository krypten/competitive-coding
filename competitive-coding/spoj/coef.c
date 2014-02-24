#include <stdio.h>
long long int fact(int n)
{
      int i;
      long long int var = 1;
      if (n == 0) return 1;

      for ( i = 1; i <= n; i++) {
            var = var *i;
      }
      return var;
}

int main()
{
      int n;
      int k,i;
      long long int sum;

      while(scanf("%d %d", &n, &k) != EOF) {
            int a[16] = {0};
            for ( i = 0; i < k; i++) {
                  scanf("%d", &a[i]);
            }

            sum = fact(n);
            for ( i = 0; i < k;i++ ) {
                  sum = sum/fact(a[i]);
            }
            printf("%lld\n", sum);
      }
      return 0;
}
