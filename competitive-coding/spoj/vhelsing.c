#include <stdio.h>
#include <math.h>

int main()
{
      double n;
      double tmp;
      long int t;
      long long int tp;
      scanf("%ld", &t);
      while (t--) {
            scanf("%lf", &n);
            tmp = n*n*n*4.686291501015239609586490206322;
            tmp = tmp*10000;
            tp = floor(tmp + 0.50);

            printf("%.4lf\n", tp/10000.0);
      }
      return 0;
}


