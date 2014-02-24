#include <stdio.h>
#include <string.h>

int M[(1<<17)][17] = {0};
int arr[(1<<17)] = {0} ;

int min(int a, int b) {
      if(a>b) return b;
      return a;
}

void process(int N)
{
      int i, j;

      for (i = 0; i < N; i++) M[i][0] = i;

      for (j = 1; (1 << j) <= N; j++)
          for (i = 0; i + (1 << j) <= N; i++) {
              if (arr[M[i][j - 1]] < arr[M[i + (1 << (j - 1))][j - 1]])
                  M[i][j] = M[i][j - 1];
              else
                  M[i][j] = M[i + (1 << (j - 1))][j - 1];
            }
}

int main()
{
      int t, n, m, i, j ,k,u;
      int a, b;
      int ans;
      scanf("%d", &t);

      for( u = 1; u <= t; u++) {
            scanf("%d %d", &n, &m);

            for(i = 0; i < n;i++) {
                  scanf("%d", &arr[i]);
            }
            process(n);
            printf("Scenario #%d:\n\n", u);

            for( i = 0; i < m; i++) {
                  scanf("%d %d", &a, &b);
			for(a--, b--, k = 1; (1 << k) <= (a - b + 1); k++); k--;
			printf("%d\n", min(arr[M[a][k]], arr[M[b - (1 << k) + 1][k]]));

            }
      }
  return 0;
}
