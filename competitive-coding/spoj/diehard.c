#include <stdio.h>

int main()
{
      int t;
      int h;
      int a;
      int ctr;

      scanf("%d", &t);
      while(t--) {
            scanf("%d %d", &h, &a);

            ctr = 0;

            while( h > 0 && a > 0) {
                  ctr++;
                  h = h + 3;
                  a = a + 2;

                  if ( h > 5 && a > 10) {
                        h = h - 5;
                        a = a - 10;
                        ctr++;
                  } else if ( h > 20 ) {
                        h = h - 20;
                        a = a + 5;
                        ctr++;
                  } else {
                        break;
                  }
            }

            printf("%d\n", ctr);
      }
      return 0;
}
