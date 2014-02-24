#include <stdio.h>
int main()
{
      int a;
      int m;
      int t;
      long long int b;
      int i;

      scanf("%d", &t);
      while (t--) {

      scanf("%d %lld", &a, &b);
      m = a;

      if ( b == 0) { printf("1\n"); continue;}
      if ( a == 1 || a == 0 || b == 1) {
      printf("%d\n", a); continue;
      }
      if (b%4==0)
            b = 4;
      else
            b=b%4;
      for ( i = 1 ; i < b; i++) {
            m = (m*a) % 10;
            if( m == 0)
                  break; }
      printf("%d\n", m);
}
return 0;
}
