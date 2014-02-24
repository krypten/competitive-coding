#include <stdio.h>
#include <math.h>

double expo(double a, int t)
{
      double var = 1;
      double mult = a;

      while(t > 0) {
            if ( t %2 == 1) {
                  var = var * mult;
            }
            mult = mult * mult;
            t = t/2;
      }
      return var;
}

int main()
{
      int t,ctr,i;
      double p, r;
      double var, ans;

      ctr = 0;
      while(1) {
            ctr++;
            scanf("%lf %lf %d", &p, &r, &t);

            if( p == 0 && r == 0 && t == 0) break;

            r = r/(100.00 * t);

            ans = p;
            for ( i = 0; i < t; i++) {
                  var = ans*r;
                  var = floor(var*100.0)/100.00;
                  if (var >= 0.01) ans = ans + var;
            }

            printf("Case %d. $%.2lf at %.2lf%% APR compounded %d times yields $%.2lf\n", ctr, p , r*100.00*t, t, ans);
      }
      return 0;
}
