#include <stdio.h>
int etf(int n)
{
      int i;
      int result = n;
      for (i = 2; i*i<= n; i++) {
      if(n%i==0)
            result -= result/i;
      while(n%i == 0)
            n /= i;
      }
      if(n>1)
            result -= result/n;
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
            printf("%d\n", etf(n, m));
      }
      return 0;
}
