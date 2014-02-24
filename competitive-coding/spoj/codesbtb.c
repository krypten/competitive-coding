#include <stdio.h>
#define MAX 300000
int arr[MAX];
int ctr;

void merge(int p, int q, int r)
{
        int n1, n2, k;
        n1 = q - p + 1;
        n2 = r - q;
        int l[100000];
        int R[100000];
        int i, j;

        for (i = 1; i <= n1; i++) {
                l[i] = arr[p + i - 1];
        }
        for (j = 1; j <= n2; j++) {
                R[j] = arr[q + j];
        }
        l[n1 + 1] = 100000008;
        R[n2 + 1] = 100000008;
        i = j = 1;
        for (k = p; k <= r; k++) {
                if (l[i] <= R[j]) {
                        arr[k] = l[i++];
                } else {
                        ctr = ctr + j+q-k;
                        arr[k] = R[j++];
                }
        }
}

void mergesort(int p, int r) {
        int q;
        if (p < r) {
                q = (p + r) / 2;
                mergesort(p, q);
                mergesort(q + 1, r);
                merge(p, q , r);
        }
}

int main()
{
      int t;
      int n;
      int i;
      scanf("%d", &t);
      while(t--) {
            scanf("%d", &n);
            for (i = 0; i < n; i++) {
                  scanf("%d", &arr[i]);
            }
            ctr = 0;
            mergesort(0, n - 1);
            //for (i = 0; i < n; i++)  printf("%d ", arr[i]);

            printf("%d\n", ctr);
      }
      return 0;
}
