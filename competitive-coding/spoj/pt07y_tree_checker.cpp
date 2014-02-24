// use bfs instead

#include <cstdio>
#include <map>
#include <vector>

using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;

vector <int>  d;
vector <vii> AdjList;
int con;
int flag = 1;

void dfs(int u) {
	int i;
	d[u] = 1;
	
	for( i = 0 ; i < (int) AdjList[u].size(); i++) {
		pair<int,int> v = AdjList[u][i];
		if( d[v.first] == 1) {
			flag = 0;
		} else if( d[v.first] == -1) {
			con++;
			dfs(v.first);
		}
	}
}
			
int main()
{
	int n, m;
	int v, u , i;
	
	scanf("%d %d", &n, &m);

	AdjList.assign(n+1, vii());
	d.assign(n+1, -1);
	con = 1;
	
	for( i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		AdjList[u].push_back(ii (v, 1));
		//AdjList[v].push_back(ii (u, 1));
	}
	
	flag = 1;

	dfs(1);

	if( con == n && flag == 1) printf("YES\n");
	else printf("NO\n");

	return 0;
}
