#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector <ii> vii;

vector <vii> AdjList;
vector <int> d_num;
vector <int> d_low;
vector <int> art;
vector <int> parent;

int ctr;
int ctr2; 
int dfsroot;
int children;

void articulation_point( int u ) {
	d_low[u] = d_num[u] = ctr++;
	for(int i = 0; i < (int) AdjList[u].size(); i++) {
		ii v = AdjList[u][i];		
		if( d_num[v.first] == -1) {
			parent[v.first] = u;
			if( u == dfsroot) {
				children++;
			}
			articulation_point(v.first);
			if(d_low[v.first] >= d_num[u]) {
				art[u] = 1;}

			d_low[u] = min(d_low[u], d_low[v.first]);
		}
		else if( v.first != parent[u]) {
			d_low[u] = min(d_low[u], d_num[v.first]);
		}
	}
}

int main()
{
	int n, m;
	int i, j;
	int u, v;

	while(1) {
		scanf("%d %d", &n, &m);
		if( n == 0 && m == 0) break;
	
		d_num.assign(n+1, -1);
		d_low.assign(n+1, 0);
		art.assign(n+1, 0);
		parent.assign(n+1, 0);
		AdjList.assign(n+1, vii());
	
		for( i = 0; i < m; i++) {
			scanf("%d %d", &u ,&v);
			AdjList[u].push_back(ii (v, 1));
			AdjList[v].push_back(ii (u, 1));
		//	printf("%d", 21);
		}
	
		ctr = 0;
		ctr2 = 0;

		for(i = 1; i<= n; i++) {
			if(d_num[i] == -1) {
				dfsroot = i; children = 0;
				articulation_point(i);
				art[dfsroot] = (children > 1);
			}
		}

		for (i = 1; i <= n; i++) {
			if (art[i]) ctr2++;		
		}
	
		printf("%d\n", ctr2);
	}
	return 0;
}
