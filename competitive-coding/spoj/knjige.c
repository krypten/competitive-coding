#include <stdio.h>

int main()
{
      int i;
      int n;
      int ctr;
      int maxi;
      int arr[400000];

      scanf("%d", &n);
      for(i = 0; i < n; i++) scanf("%d", &arr[i]);
      maxi = arr[0]; ctr= 1;
      for( i = 1; i < n; i++) {
            if( arr[i] == (maxi + 1)) {ctr++; maxi = arr[i];}
            else if(arr[i] > maxi) {ctr = 1; maxi = arr[i];}
      }
      printf("%d\n", n-ctr);
      return 0;
}
