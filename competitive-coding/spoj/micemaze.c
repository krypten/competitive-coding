#include <stdio.h>

#define MAX 128

void floyd(int (*d)[][MAX], int n)
{
      int i;
      int j;
      int k;

      for (k = 1; k <= n; k++) {
            for (i = 1; i <= n; i++) {
                  for (j = 1; j <= n; j++) {
                        if ((*d)[i][k] + (*d)[k][j] < (*d)[i][j]) {
                              (*d)[i][j] = (*d)[i][k] + (*d)[k][j];
                        }
                  }
            }
      }
}

int main()
{
	int i,j,k;
	int n, m;
	int tmp;
	int u, v;
	int e, t;
	int adj[MAX][MAX];

      scanf("%d", &n);
      scanf("%d", &e);
      scanf("%d", &t);
      scanf("%d", &m);

      for(i = 0; i <= n; i++) {
            for(j = 0; j <= n; j++) {
                  adj[i][j] = 100000000;
			if( i == j ) adj[i][i] = 0;}}


      for(i = 0; i < m; i++) {
            	scanf("%d %d %d",&u, &v, &tmp);
		adj[u][v] = tmp;
      }

	floyd(&adj,n);

	k = 0;
	for( i = 1; i <= n; i++) {
		if(adj[i][e] <= t) {
			k++;}
	}
	printf("%d\n", k);

      return 0;
}
