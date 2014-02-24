#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
      int i, j, k;
      int n, m;
      int u, v, w;
      double adj[128][128];

      while(1) {
            scanf("%d", &n);
            if (n == 0) break;

            scanf("%d", &m);
            memset(adj, 0, sizeof(adj));

            for (i = 1; i <= n; i++) {
                  adj[i][i] = 1;
            }

            for (i = 0; i < m; i++) {
                  scanf("%d %d %d", &u, &v, &w);

                  if(adj[u][v] < w/100.0) {
                        adj[u][v] = w/100.0;
                        adj[v][u] = w/100.0;
                  }
            }


            for (k = 1; k <= n; k++) {
                  for (i = 1; i <= n; i++) {
                        for (j = 1; j <= n; j++) {
                              if (adj[i][k]*adj[k][j] > adj[i][j]) {
                                    adj[i][j] = adj[i][k]*adj[k][j];
                              }
                        }
                  }
            }

            printf("%.6lf percent\n", adj[1][n]*100);
      }
      return 0;
}
