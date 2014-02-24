#include <cstdio>
#include <set>
#include <cstring>

#define MAX 256
using namespace std;

set <pair<int,int> > m;
set <pair<int,int> > :: iterator it;
int adj[MAX][MAX] ;

void floyd(int n)
{
      int i;
      int j;
      int k;
      int flag,key,value;

      for (i = 0; i < n; i++) {
            for (j = i+1; j < n; j++) {
                  flag = 0;
                  for (k = 0; k < n; k++) {
                        if (adj[i][k] + adj[k][j] == adj[i][j] && i!=k && j!=k && i != j) {
                             flag = 1;
                        }
                  }
                  if ( flag == 0) {
                        if(j > i) {
                              key = i;
                              value = j;
                        } else {
                              key = j;
                              value = i;
                        }
                        it = m.find(pair<int, int > (key,value));
                        if ( it == m.end()) {
                              m.insert(pair<int, int> (key, value));
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

	scanf("%d", &t);
	ctr = 0;
	while(t--) {
		ctr++;
      memset(adj, 0, sizeof(adj));

      scanf("%d", &n);

      for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                  scanf("%d", &adj[i][j]);
            }
      }

      floyd(n);

      for ( it = m.begin(); it != m.end(); it++) {
            printf("%d %d\n", it->first + 1, it->second + 1); }

      m.clear();
      if(t > 0)      printf("\n");
      }
      return 0;
}
