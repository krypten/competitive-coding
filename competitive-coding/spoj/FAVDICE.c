#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
      double ans;
      double tmp;
      long double tmp1;
      long long int t;
      long long int tp;
      int n;
      scanf("%lld", &t);
      while(t--) {
            scanf("%d", &n);
            tmp = n;
            ans = log(tmp) + 0.57721566 + (1.0/(2*tmp)) - (1.0/(12*tmp*tmp)) + (1.0/(120*tmp*tmp*tmp*tmp));
            tmp1 = n*ans*100;
            tp = llrint(tmp1);
            printf("%.2lf\n", tp/100.0);
      }
      return 0;
}
