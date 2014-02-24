#include <stdio.h>
#include <math.h>

int main()
{
      long int t;
      long int g;
      long int b;
      while (1) {
            scanf("%ld %ld", &g, &b);
            if(g == -1 && b == -1) {
                  break;
            }
            if(g == 0) {
                  if (b == 0) {
                        printf("0\n");
                        continue;
                  } else {
                        printf("%ld\n", b);
                        continue;
                  }
            } else if (b == 0) {
                  printf("%ld\n", g);
                  continue;
            }
            if( g == b) {
                  printf("1\n");
                  continue;
            }
            if( g > b) {
                  t = ceil(g/(b+1.0));
            } else {
                  t = ceil(b/(g+1.0));
            }
            printf("%ld\n", t);
      }
      return 0;
}
