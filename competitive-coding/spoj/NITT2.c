#include <stdio.h>
#include <string.h>

void check2( char * stp)
{
      int tmp;
      long int len;
      long int i;
      long long int sum = 0;
      len = strlen(stp);
      for (i =0 ;i<len; i++) {
            sum += (stp[i] - '0');
      }
      if (sum%9 != 0) {
            printf("No");
            return;
      }
      sum = ((stp[len-1]- '0') + (stp[len-2] - '0')*10);
      if (sum%4 != 0) {
            printf("No");
            return;
      }
      sum = 0;
      for (i = 1; i <= len; i++) {
            tmp = i%6;
            switch(tmp) {
                  case 1: sum = sum + (stp[len-i] - '0');break;
                  case 2: sum = sum + 3*(stp[len-i] - '0');break;
                  case 3: sum = sum + 2*(stp[len-i] - '0');break;
                  case 4: sum = sum + 6*(stp[len-i] - '0');break;
                  case 5: sum = sum + 4*(stp[len-i] - '0');break;
                  case 0: sum = sum + 5*(stp[len-i] - '0');break;
      }}
      if (sum%7 != 0) {
            printf("No");
            return;
      }
      printf("Yes");
}

void check5( char * stp)
{
      int tmp;
      long int len;
      long int i;
      long long int sum = 0;
      len = strlen(stp);
      for (i =0 ;i<len; i++) {
            sum += (stp[i] - '0');
      }
      if (sum%3 != 0) {
            printf("No");
            return;
      }
      sum = ((stp[len-1]- '0') + (stp[len-2] - '0')*10);
      if (sum%25 != 0) {
            printf("No");
            return;
      }
      sum = 0;
      for (i = 1; i <= len; i++) {
            tmp = i%6;
            switch(tmp) {
                  case 1: sum = sum + (stp[len-i] - '0');break;
                  case 2: sum = sum + 3*(stp[len-i] - '0');break;
                  case 3: sum = sum + 2*(stp[len-i] - '0');break;
                  case 4: sum = sum + 6*(stp[len-i] - '0');break;
                  case 5: sum = sum + 4*(stp[len-i] - '0');break;
                  case 0: sum = sum + 5*(stp[len-i] - '0');break;
      }}
      if (sum%7 != 0) {
            printf("No");
            return;
      }
      printf("Yes");
}

int main()
{
      int t;
      long int len;
      char str[65536];
      scanf("%d", &t);
      while (t--) {
            scanf("%s", str);
            len = strlen(str);
            if (len < 3) {
                  printf("No No\n");
                  continue; }
            check2(str);
            printf(" ");
            check5(str);
            printf("\n");
      }
      return 0;
}
