#include <stdio.h>
#include <math.h>

int main()
{
      double n;
      double tmp;
      long double pi= 0;
      long int t;
      long long int tp;
      scanf("%ld", &t);
      while (t--) {
            scanf("%lf", &n);
            if(n == 1 || n == 0) {
                  printf("1\n");
                  continue;
            }
            tp = floor((log(2.0*3.14159265358979323 *n)/2.0+n*(log(n)-1))/log(10))+1;
            printf("%lld\n", tp);
      }
      return 0;
}
