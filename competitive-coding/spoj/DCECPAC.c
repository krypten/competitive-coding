#include <stdio.h>
#include <string.h>

int fi(int n)
     {
       int result = n,i;
       for(i=2;i*i <= n;i++)
       {
         if (n % i == 0) result -= result / i;
         while (n % i == 0) n /= i;
       }
       if (n > 1) result -= result / n;
       return result;
     }


int main()
{
      long int t;
      long int n;
      long int i;
      long long int h;
      scanf("%ld", &t);
      while (t--) {
            scanf("%ld", &n);
            h = 0;
            for( i = 1; i <= n; i++) {
                  h = h + fi(i);
            }
            printf("%lld\n", h*h);
      }
      return 0;
}
