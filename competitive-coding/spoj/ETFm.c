#include <stdio.h>
long int etf(long int n, long int m)
{
      int flag= 0;
      long int i;
      long int result = m;
      for (i = 2; i*i<= n; i++) {
      if(i == m) {
            break;
      }
      if(n%i==0)
            result -= result/i;
            flag = 1;
      while(n%i == 0)
            n /= i;
      }
      return result;
}

int main()
{
      long int t;
      long int n;
      long int m;
      scanf("%ld", &t);
      while (t--) {
            scanf("%ld %ld", &n, &m);
            printf("%ld\n", etf(n, m));
      }
      return 0;
}
