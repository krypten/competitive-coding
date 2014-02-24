#include <stdio.h>

int main()
{
      int t;
      int ctr;
      long long int r;
      scanf("%d", &t);
      ctr = 1;
      while(t--) {
            double sum = 0.0;
            scanf("%lld", &r);
            sum = 4*r*r + 0.25;
            printf("Case %d: %.2lf\n", ctr++, sum);
      }
      return 0;
}
