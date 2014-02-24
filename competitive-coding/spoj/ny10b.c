/* TODO:
      store the sum in array of int and also convert the sum into base b and then add mod B____
*/

#include <stdio.h>

int main()
{
      int t;
      int ct;
      int i,j,k;
      int ans,a,b,n;
      int sum[100];
      int a1[100];
      int b1[100];

      scanf("%d", &t);
      while (t--) {
            scanf("%d %d %d %d", &ct, &n, &a, &b);
            i = 0;
            while( a != 0) {
                  a1[i++] = a%n;
                  a = a/n;
            }
            j = 0;
            while( b != 0) {
                  b1[j++] = b%n;
                  b = b/n;
            }

            if (i > j) {
                  for ( k = 0; k < j; k++ ) {
                        sum[k] = (a1[k] + b1[k]) % n;
                  }
                  while (k < i) {
                        sum[k] = a1[k];
                        k++;
                  }
            } else {
                  for ( k = 0; k < i; k++ ) {
                        sum[k] = (a1[k] + b1[k]) % n;
                  }
                  while (k < j) {
                        sum[k] = b1[k];
                        k++;
                  }
            }

            ans = 0;
            while( k > 0 ) {
                  k--;
                  ans = ans * n + sum[k];
            }

            printf("%d %d\n", ct, ans);
      }
      return 0;
}
