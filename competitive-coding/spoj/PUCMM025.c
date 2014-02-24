/* TODO : add memorisation of digits to speed up
*/

#include <stdio.h>
#include <string.h>

int check8( char * stp)
{
      int tmp;
      long int len;
      long int i;
      int sum = 0;
      len = strlen(stp);
      sum = ((stp[len-1]- '0') + (stp[len-2] - '0')*10);
      if (len > 2) { sum = sum + (stp[len-3] - '0')*100;}
      if (sum%8 != 0) {
            return 0;
      }
      return 1;
}

int check7(char * stp)
{
      int i;
      int len;
      int tmp;
      long long int sum = 0;
      len = strlen(stp);
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
            return 0;
      }
      return 1;
}

int check3 (char * stp)
{
      long int len;
      long int i;
      long long int sum = 0;
      len = strlen(stp);
      for (i =0 ;i<len; i++) {
            sum += (stp[i] - '0');
      }
      if (sum%3 != 0) {
            return 0;
      }
      return 1;
}
int check9 (char * stp)
{
      long int len;
      long int i;
      long long int sum = 0;
      len = strlen(stp);
      for (i =0 ;i<len; i++) {
            sum += (stp[i] - '0');
      }
      if (sum%9 != 0) {
            return 0;
      }
      return 1;
}

int main()
{
      int tmp;
      long int len;
      long int i;
      long int ctr;
      char str[256];
      while (scanf("%s", str) != EOF) {
            int arr[10] = {0};
            len = strlen(str);
            ctr = 0;
            if (len < 2) {
                  printf("1\n");
                  continue;
            }
            arr[1] = 1;
            arr[2] = ((str[len-1]-'0')%2 == 0);
            arr[3] = (check3(str));
            arr[4] = (((str[len-1] - '0') + (str[len-2] - '0')*10)%4 == 0);
            arr[5] = ((str[len-1]-'0')%5 == 0);
            arr[6] = (!(!(((str[len-1]-'0')%2 == 0 ) && arr[3])));
            arr[7] = check7(str);
            arr[8] = (check8(str));
            arr[9] = (check9(str));

            for (i =0 ;i<len; i++) {
                  tmp = (str[i] - '0');
                  ctr = ctr + arr[tmp];
            }
            printf("%ld\n", ctr);
      }
      return 0;
}
