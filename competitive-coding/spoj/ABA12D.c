#include <stdio.h>

int main()
{
      int i;
      long long int a;
      long long int b;
      long long int tc;
      long long int ctr;
      long long int arr[] = { 2, 4, 9, 16, 25, 64, 289, 729, 1681, 2401, 3481, 4096, 5041, 7921,  \
                  10201, 15625, 17161, 27889, 28561, 29929, 65536, 83521, 85849,                \
                  146689, 262144, 279841, 458329, 491401, 531441, 552049, 579121, 597529, 683929, 703921, 707281, 734449, 829921, 1190281 };

      scanf("%lld", &tc);

      while(tc--) {
            scanf("%lld %lld", &a, &b);
            i = 0;
            ctr = 0;
            while(i < 38) {
                  if (a <= arr[i] && arr[i] <= b) {
                        ctr++;
                  }
                  i++;
            }

            printf("%lld\n", ctr);
      }

      return 0;
}
