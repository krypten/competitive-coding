#include <stdio.h>

int main()
{
      int flag;
      int n, i;
      int arr[100002];
      int arr3[100002];

      while(1) {
            scanf("%d", &n);
            if (n  == 0 )  break;

            for ( i = 0; i < n; i++) {
                  scanf("%d", &arr[i]);
            }
            for ( i = 0; i < n; i++) {
                  arr3[arr[i] - 1] = i+1;
            }
            flag = 0;
            for(i = 0; i < n; i++) {
                //  printf("%d %d", arr[i], arr3[i]);
                  if (arr[i] != arr3[i]) {
                        flag = 1;
                        break;
                  }
            }
            if ( flag) {
                  printf("not ambiguous\n");
            } else {
                  printf("ambiguous\n");
            }
      }
      return 0;
}
