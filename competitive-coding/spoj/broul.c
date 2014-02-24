#include <stdio.h>

int main()
{
      int po;
      int pt;
      int wt;
      int dif;
      int q3;
      int q2;
      int q1;

      while (scanf("%d %d %d", &po, &wt, &pt) != EOF) {
            if( po == 0 && pt == 0 && wt == 0)
                  break;
            if(po == pt) {
                  printf("0\n");
                  continue;
            }
            if ( pt > po) {
                  dif = pt - po;
            } else {
                  dif = po - pt;
            }
            if ( dif%wt != 0) {
                  printf("No accounting tablet\n");
                  continue;
            }
            dif = dif/wt;
            q3 = dif/3;
            q2 = (dif - 3*q3)/2;
            q1 = dif - 3*q3 - q2*2;
            printf("%d\n", q3 + q2 + q1);
      }
      return 0;
}
