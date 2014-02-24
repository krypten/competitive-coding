#include <stdio.h>
long long int fun (long long int n)
{
      if (n == 1)
            return 1;
      if (n == 0)
            return 1;
      return (fun(n-1) + fun(n-2));
}
int main()
{
      long long int x;
      while (scanf("%lld", &x) != EOF) {
            printf("\t%lld\n", fun(x));
      }
      return 0;
}
