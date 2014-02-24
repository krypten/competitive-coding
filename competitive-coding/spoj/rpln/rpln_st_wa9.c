#include <stdio.h>
#include <string.h>
#define LONG_LONG_MIN -1000000000012

long long int arr[100024];
long long int  st[550024];

int left (int p) { return p << 1; }     // same as binary heap operations
int right(int p) { return (p << 1) + 1; }

void build(int p, int L, int R) {                           // O(n log n)
    if (L == R)                            // as L == R, either one is fine
      st[p] = arr[L];                                         // store the index
    else {                                // recursively compute the values
      build(left(p) , L              , (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R          );
      long long int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (p1 <= p2) ? p1 : p2;
  } }

long long int rmq(int p, int L, int R, int i, int j) {                  // O(log n)
    if (i >  R || j <  L) return LONG_LONG_MIN; // current segment outside query range
    if (L >= i && R <= j) return st[p];               // inside query range

     // compute the min position in the left and right part of the interval
    int mid = (L+R)>>1;
    long long int p1 = rmq(left(p) , L  , mid, i, mid);
    long long int p2 = rmq(right(p), mid + 1, R , mid+1, j);

      if(p1 == LONG_LONG_MIN ) return p2;
      if(p2 == LONG_LONG_MIN ) return p1;

    return (p1 <= p2) ? p1 : p2;          // as as in build routine
}

int main() {
      int t, n, m, i, j ,k;
      int a, b;
      long long int ans;
      scanf("%d", &t);

      memset(st, 0 , sizeof(st));
      memset(arr, 0 , sizeof(arr));
      for( k = 0; k < t; k++) {
            scanf("%d %d", &n, &m);

            printf("Scenario #%d:\n\n", k+1);

            for(i = 0; i < n;i++) {
                  scanf("%lld", &arr[i]);
            }
            build(1, 0 , n-1);
            for( i = 0; i < m; i++) {
                  scanf("%d %d", &a, &b);
                  ans = rmq(1, 0 , n-1, --a, --b);
                  printf("%lld\n", ans);
            }
      }
  return 0;
}

/* WA At 9th case*/
