#include <stdio.h>
#include <string.h>

long long int gcd(long long int a, long long int b)
{
      if(a%b == 0)
            return b;
      return gcd(b, a%b);
}

int main()
{
      char str[32];
      int i;
      int j;
      int len;
      int flag;
      long long int m;
      long long int g;

      scanf("%s", str);
      while(1) {
            char N[32] = {0};
            if (str[0] == '*') {
                  break;
            }
            m = 1;
            flag = 0;
            len = strlen(str);
//TODO : gcd factor to be g=divided and take care of mutiple of them.
            for(i = 0,j = 0; i < len; i++) {
                  if (str[i] =='Y') {
                        m = m * (i+1);
                  } else {
                        N[j++] = i + 1;
                  }
            }
            while(--j>0) {
                  if (m%N[j] == 0) {
                        flag = 1;
                        break;
                  }
            }
            if( flag == 0) {
                  printf("%llu\n", m);
            } else {
                  printf("-1\n");
            }


      scanf("%s", str);
      }
      return 0;
}
