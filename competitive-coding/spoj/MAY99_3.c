#include <stdio.h>

long long int gcd(long long int a, long long int b)
{
      if ( a%b == 0 )
            return b;
      return gcd(b, a%b);
}

int main()
{
      int tc;
      long long int x;
      long long int y;
      long long int z;

      scanf("%d", &tc);
      while(tc--) {
            scanf("%lld %lld %lld", &x, &y, &z);

            if(z > x  && z > y) {
                  printf("NO\n");
            } else if ((z % gcd(x,y)) == 0) {
                  printf("YES\n");
            } else {
                  printf("NO\n");
            }
      }

      return 0;
}
