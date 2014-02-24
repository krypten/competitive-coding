#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

vector <ii> adj;
vector <int>  visited;
int flag;

void para( int i , int con) {
	if( visited[i] == 1 || visited[i] == 2) {
		if( con == visited[i] || (con == 0 && visited[i] == 2)) return;
		else {
			flag = 1;
			return;
		}
	}

	if (con == 1) {
		visited[i] = 1;
		return para(adj[i].first, adj[i].second);
	} else {
		visited[i] = 2;
		if( adj[i].second == 1) 
			return para(adj[i].first,  0);
		else 
			return para(adj[i].first, 1);
	}
}

int main()
{
	int i ,j;
	int w, n;
	int u, v;
	char tmp[8];

	while(1) {
		flag = 0;
	
		scanf("%d", &n);
		if( n == 0) break;

		adj.clear();
		visited.assign(n+1, 0);

		adj.push_back(ii (0 , 1));

		for( i = 1; i<= n; i++ ) {
			scanf("%d %s", &j, tmp);

			if(strcmp(tmp, "true") == 0) w = 1;
			else w = 0;

			adj.push_back(ii ( j, w));
		}

		for( i = 1; i <= n; i++) {
			if( visited[i] == 0) {
				para( i, 1) ;
				visited.assign(n+1, 0);
				if(flag) break;
			}
		}
		
		if(flag) printf("PARADOX\n");
		else printf("NOT PARADOX\n");

	}

	return 0;
}
