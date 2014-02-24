#include <stdio.h>
#include <string.h>
int main()
{
      int m;
      int t;
      int tmp;
      int len;
      unsigned long long int b;
      int i;
      scanf("%d", &t);
      while (t--) {
      char a[1024];
      scanf("%s %llu", a, &b);
      len = strlen(a);
      m = (a[len - 1] - '0');
      tmp = m;
      if ( b == 0) { printf("1\n"); continue;}
      if ( m == 1 || m == 0 || b == 1) {
      printf("%d\n", m); continue;
      }
      if (b%4==0)
            b = 4;
      else
            b=b%4;
      for ( i = 1 ; i < b; i++) {
            m = ((m*tmp) % 10);
            if( m == 0)
                  break; }
      printf("%d\n", m);
}return 0;
}
