#include <stdio.h>

int main()
{
      int n;
      long long int tmp;
      while(1) {
            scanf("%d", &n);
            if (n++ == 0)
                  break;
            tmp = (n*(3*n-1)/2);
            printf("%lld\n", tmp);
      }
      return 0;
}
