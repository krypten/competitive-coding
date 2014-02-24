#include <stdio.h>
#include <string.h>

long long int ft[2000020];
#define LSOne(S) (S & (-S))


long long int rsq(long long int b) {
    long long int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }


 void adjust(long long int k, long long int v) {
    for (; k < (int)2000020; k += LSOne(k)) ft[k] += v; }

int main()
{
      int t;
      int n, i;
      int tmp;
      long long int sum;
      int arr[100020];

      scanf("%d", &t);
      while(t--) {
            fflush(stdin);
            scanf("%d", &n);
            memset(ft, 0, sizeof(ft));
            memset(arr, 0, sizeof(arr));
            for(i = 1; i <= n; i++) {
                  scanf("%d", &tmp);
                  if (tmp > 0) arr[i] = tmp;
                  else {i--;n--;}
            }

            sum = 0;
            for (i = 1; i <= n; i++) {
                  sum = sum + rsq(arr[i] - 1);
                  adjust(arr[i], arr[i]);
            }

            printf("%lld\n", sum);
      }
      return 0;
}
