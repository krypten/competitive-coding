#include <stdio.h>

int main()
{
      int t;
      int tmp;
      unsigned long long int n;
      unsigned long long int n2;
      int g;

      scanf("%d", &t);
      while(t--) {
            tmp = 0;
            g = 0;
            scanf("%llu", &n);
            if ( n == 1) {
                  printf("1 0\n");
                  continue;
            }
            n2 = n - 1;
            while(n2>>=1) tmp++;
            n2 = 1;
            n2 <<=tmp+1;

            while (n) {
                  if((n%2 == 0)){// && (n != 0)) {
                        n = n>>1;
                        g++;
                  } else {
                        break;
                  }
            }
            printf("%llu %d\n", n2, tmp - g + 1);
      }
      return 0;
}
