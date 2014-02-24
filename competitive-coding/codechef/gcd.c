#include <stdio.h>
int steps, tmp;

void sub_gcd (int a, int b) {
      while (a >= b) {
      if (a%b == 0 && a != b) {
            steps += 1;
            return;
      } else if (a == b) {
            return;
      } else if (a%b == 1) {
            if (a > 2*b) {
                  tmp = b;
                  b = (a % b) + b;
                  a = tmp;
            } else {
                  tmp = b;
                  b = a % b;
                  a = tmp;
            }
            steps += 1;

      } else if (a%b > 1) {
            tmp = b;
            b = a % b;
            a = tmp;
            steps += 1;
      }
      }
      return ;
}

int main () {
      int t;
      int n;
      int p,q;

      scanf("%d", &t);
      while(t--) {
            steps = 0;
            scanf("%d", &n);
            while (n--) {
                  scanf("%d %d", &p,&q);
                  if (q > p ) {
                        tmp = p;
                        p = q;
                        q = tmp;
                  }
                  sub_gcd(p, q);
            }
            if (steps % 2 == 1) {
                  printf("YES\n");
            } else {
                  printf("NO\n");
            }
      }

      return 0;
}
