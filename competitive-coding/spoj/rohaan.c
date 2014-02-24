#include <stdio.h>

#define MAX 64

void floyd(int (*d)[][MAX], int n)
{
      int i;
      int j;
      int k;

      for (k = 0; k < n; k++) {
            for (i = 0; i < n; i++) {
                  for (j = 0; j < n; j++) {
                        if ((*d)[i][k] + (*d)[k][j] < (*d)[i][j]) {
                              (*d)[i][j] = (*d)[i][k] + (*d)[k][j];
                        }
                  }
            }
      }
}

int main()
{
      int i,r;
      int j,k;
      int n,ctr;
      int sum,t;
      int source;
      int destination;
      int adj[MAX][MAX] = {0};
      int pie[MAX][MAX] = {0};

	scanf("%d", &t);
	ctr = 0;
	while(t--) {
		ctr++;

      scanf("%d", &n);

      for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                  scanf("%d", &adj[i][j]);
            }
      }

      floyd(&adj, n);

	scanf("%d", &r);
	sum = 0;
	for (k = 0; k < r; k++) {

		scanf("%d %d", &source, &destination);
		sum = sum + adj[source-1][destination-1];
	}
	printf("Case #%d: %d\n", ctr, sum);
	}
      return 0;
}
