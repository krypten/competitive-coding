#include <stdio.h>

int gcd(int a, int b)
{
      if(a%b == 0)
            return b;
      return gcd(b, a%b);
}

int main()
{
      int n;
      int i;
      int x[1024];
      int y[1024];
      int z[1024];
      int g;
      long long int sum;
      scanf("%d", &n);
      while(n != 0) {
            sum = 0;
            for(i = 0; i<n; i++) {
                  scanf("%d %d %d", &x[i], &y[i], &z[i]);
            }
            g = x[0];
            for(i = 0; i<n; i++) {
                  g = gcd(g, x[i]);
                  g = gcd(g, y[i]);
                  g = gcd(g, z[i]);
            }
            for(i = 0; i<n; i++) {
                  sum = sum + (x[i]*y[i]*z[i])/(g*g*g);
            }
            printf("%lld\n", sum);
      scanf("%d", &n);
      }
      return 0;
}
