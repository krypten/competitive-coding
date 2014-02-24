#include <stdio.h>

int main()
{
      int i;
      int t;
      int k;
      float n;
      float tmp;

      while(1) {
            scanf("%f", &n) ;
            if (n == 0)
                  break;
            k = 2;
            i = 1;
            tmp = 0;
            while ((tmp = tmp + 1.0/k) < n) {
                  ++k;
                  i++;
            }
            printf("%d card(s)\n", i);
      }
      return 0;
}

