/*
      Be careful with this case
      4 1 2 3 4
      4 5 6 7 8
      ANS:26

      like merge function in merge sort, compare the sum of numbers and then intersection and store the max of it.
*/

#include <stdio.h>
#include <string.h>

int main()
{
      int n;
      int m;
      int i;
      int j;
      long long int sum;
      long long int sum1;
      long long int sum2;

      int arr1[100000];
      int arr2[100000];

      while (1) {
            scanf("%d", &n);
            memset(arr1, 0, sizeof(arr1));
            memset(arr2, 0, sizeof(arr2));

            if ( n == 0) { break; }

            for (i = 0; i < n; i++) {
                  scanf("%d", &arr1[i]);
            }

            scanf("%d", &m);
            for (i = 0; i < m; i++) {
                  scanf("%d", &arr2[i]);
            }

            sum = 0;
            sum1 = 0;
            sum2 = 0;

            for ( i = 0, j = 0; i < n && j < n;) {
                  if (arr1[i] > arr2[j]) {
                        sum2 = sum2 + arr2[j];
                        j++;
                  } else if ( arr1[i] < arr2[j]) {
                        sum1 = sum1 + arr1[i];
                        i++;
                  } else if ( arr1[i] == arr2[j]) {
                        sum = sum + arr1[i];
                        //printf("\n %d %d %d \n", sum, sum1, sum2);
                        if ( sum1 > sum2) {
                              sum = sum + sum1;
                        } else {
                              sum = sum + sum2;
                        }
                        sum1 = sum2 = 0;
                        i++; j++;
                  }
            }

            while ( i < n ) {
                  sum1 = sum1 + arr1[i++];
            }
            while ( j < m) {sum2;
                  sum2 = sum2 + arr2[j++];
            }
            if ( sum1 > sum2 ) {
                  sum = sum + sum1;
            } else {
                  sum = sum + sum2;
            }

            printf("%d\n", sum);
      }
      return 0;
}
