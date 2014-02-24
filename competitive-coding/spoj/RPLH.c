#include <stdio.h>
#include <math.h>

int main()
{
      double g = 9.806;
      double pi = 2*acos(0.0);
      double tmp;
      long int t;
      long int d;
      long int v;
      long int i;
      scanf("%ld", &t);
      for(i = 0; i < t; i++) {
            scanf("%ld %ld", &d , &v);
            tmp = asin((d*g)/(v*v))*180.0/pi;
            if (tmp <= 90)
                  printf("Scenario #%ld: %.2lf\n",i+1, tmp/2);
            else
                  printf("Scenario #%ld: -1\n",i+1);
      }
      return 0;
}
