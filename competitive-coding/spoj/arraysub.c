#include <stdio.h>
#include <stdlib.h>

int main()
{
      int t;
      int i;
      int j;
      int n;
      int k;
      int pos;
      int maxx;
      int *arr;
      int *arr2;

      scanf("%d\n", &n);
      arr = (int * ) malloc(sizeof(int) * (n+1));
      for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
      }
      scanf("%d", &k);
      arr2 = (int * ) malloc(sizeof(int) * (k+1));
      pos = 0;
      for (j = 0;  j <= (n-k); j++) {
            if ( j >= pos) {
                  maxx = arr[j];
                  pos = j;
                  for (i = j; i < j+k; i++ ) {
                        if(arr[i] > maxx) {
                              maxx = arr[i];
                              pos = i;
                        }
                  }
            } else if ( arr[j+k-1] > maxx) {
                  maxx = arr[j+k-1];
                  pos = j+k - 1;
            }
            if ( j == n-k)
                  printf("%d\n",maxx);
            else
                  printf("%d ", maxx);
     }
      return 0;
}
