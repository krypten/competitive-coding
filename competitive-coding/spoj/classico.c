#include <stdio.h>

int main()
{
      int t;
      int arr[2048];
      int ans[11];
      int n;
      int ctr,i,j,k;
      int maxi;
      int maxi_ctr;

      scanf("%d", &t);

      for( ctr = 0 ;ctr < t; ctr++) {

            scanf("%d", &n);

            for(i = 0; i < n; i++) {
                  scanf("%d", &arr[i]); }
            if( n < 11) {
                  printf("Case %d: go home!\n", ctr + 1);
                  continue;
            }

            maxi_ctr = -1;
            for(j = 10; j >= 0; j--) {
                  maxi = 0;
                  for(i = maxi_ctr+1; i < n - j; i++) {
                        if( arr[i] > maxi) {
                              maxi_ctr = i;
                              maxi = arr[i];
                        }
                  }
                  ans[10-j] = maxi;
            }
            printf("Case %d: ", ctr + 1);

            for( i = 0; i < 10; i++ ) {
                  printf("%d ", ans[i]);
            }
            printf("%d\n", ans[10]);
      }
      return 0;
}
