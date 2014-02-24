#include <stdio.h>

int main()
{
      int t;
      unsigned long long int tmp1;
      unsigned long long int tmp2;
      unsigned long long int tmp3;
      unsigned long long int n;
      unsigned long long int sum;

      scanf("%d", &t);
      while (t--) {
            scanf("%llu", &n);
            sum = 0;
            tmp1 = n/3.0;
            tmp2 = n/5.0;
            if (n%3 == 0)
                  tmp1--;
            if (n%5 == 0)
                  tmp2--;
            if (tmp1%2 == 0) {
                  tmp3 = tmp1>>1;
                  sum = sum + 3*tmp3*(++tmp1);
            } else {
                  tmp3 = (tmp1+1)>>1;
                  sum = sum + 3*tmp3*tmp1;
            }
            if (tmp2%2 == 0) {
                  tmp3 = tmp2>>1;
                  sum = sum + 5*tmp3*(++tmp2);
            } else {
                  tmp3 = (tmp2+1)>>1;
                  sum = sum + 5*tmp3*tmp2;
            }
            tmp3 = n/15;
            if (n%15 == 0)
                  tmp3--;
            sum = sum - (15*(tmp3*(tmp3 + 1)/2));
            printf("%llu\n", sum);
      }
      return 0;
}
