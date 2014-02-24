#include <stdio.h>

struct point {
      int x;
      int y;
};
int area[1024][1024];
int main() {
      struct point p1, p2, p3, p4;
      int t,i,j,n;
      int ctr;

      scanf("%d", &t);
      while (t--) {
            ctr = 0;
            memset(area, 0 , sizeof(area));
            scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
            scanf("%d %d %d %d", &p3.x, &p3.y, &p4.x, &p4.y);

            for ( i = p1.x; i < p2.x; i++) {
                  for ( j = p1.y; j < p2.y; j++) {
                        area[i][j] = 1;
                  }
            }

            for ( i = p3.x; i < p4.x; i++) {
                  for ( j = p3.y; j < p4.y; j++) {
                        area[i][j] = 1;
                  }
            }

            for ( i = 0; i < 1001; i++) {
                  for ( j = 0; j < 1001; j++) {
                        if (area[i][j] == 1) {
                              ctr++;
                        }
                  }
            }

            printf("%d\n", ctr);

      }
      return 0;
}
