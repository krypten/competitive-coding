#include <stdio.h>
#include <math.h>

int main()
{
      int t;
      int d;
      int m;
      int y;
      int c;
      char str[][10] = { "Sunday" , "Monday", "Tuesday", "Wednesday" , "Thursday", "Friday", "Saturday" };

      scanf("%d", &t);
      while (t--) {
            scanf("%d %d %d", &d, &m, &y);
            if (m < 3) {
                  m = m + 10;
                  y--;
            } else {
                  m = m - 2;
            }
            c = y/100;
            y = y%100;

            c = d + floor((2.6)*m - 0.2) - 2*c + y + floor(c/4) + floor(y/4);
            c = c%7;
            if ( c < 0) {
                  c = (c + 7)%7;
            }
            printf("%s\n",str[c]);
      }

      return 0;
}
