#include <stdio.h>
#include <math.h>

int main()
{
      int t;
      double n;
      double tmp;
      scanf("%d", &t);
      while (t--) {
            scanf("%lf", &n);
            tmp = 0.5*(0.5 + 1.0/(n+2) - 1.0/(n+1)) + 0.5;
            printf("%.11lf\n", tmp);
      }
      return 0;
}
