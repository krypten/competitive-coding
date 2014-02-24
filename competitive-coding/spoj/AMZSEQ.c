#include <stdio.h>
long long int fun (long long int n)
{
      if (n == 1)
            return 3;
      if (n == 0)
            return 1;
      return (2*fun(n-1) + fun(n-2));
}
int main()
{
      long long int x;
      while (scanf("%lld\n", &x) != EOF) {
            printf("%lld\n", fun(x));
      }
      return 0;
}
