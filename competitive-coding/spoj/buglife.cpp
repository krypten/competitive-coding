/*
 *  Author		: Krypten
 *  Algorithm	: Vertex Two Color
 */

#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

#define INF INT_MAX/2
#define ONLINE_JUDGE 1

#define ull 		unsigned long long
#define ill 		long long int
#define pii 		pair<int,int>
#define pb(x) 		push_back(x)
#define mp make_pair
#define F(i,a,n) 	for(int i=(a);i<(n);++i)
#define FI(i,a,n) 	for(i=(a);i<(n);++i)
#define FD(i,a,n) 	for(int i=(a);i>=(n);--i)
#define FE(it,x) 	for(it=x.begin();it!=x.end();++it)
#define V(x) 		vector<x>
#define S(x) 		scanf("%d",&x)
#define Sl(x) 		scanf("%lld",&x)
#define Ss(x)		scanf("%s", x)
#define P(x) 		printf("%d",x)
#define Pl(x) 		printf("%lld",x)
#define Ps(x)		printf("%s", x)
#define M(x,i) 		memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) 	((a)>(b)?(a):(b))
#define MIN(a,b) 	((a)>(b)?(b):(a))

ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

void input() {
#if !ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}


#define BLUE 0
#define PINK 1
#define UNCOLORED -1

#define SIZE 2048

int color[SIZE1];
int visited[SIZE1];
bool matrix[SIZE1][SIZE1];

void bfs(int source, int n, bool &flag)
{
	queue<int> q;
	q.push(source);
        
	while(!q.empty()) {
		int i = q.front();
		q.pop();
       	
       	if (visited[i])
       		continue;
       	visited[i] = true;

		F(j,1,n+1) {
	    	if ((i != j) && matrix[i][j]) {
	    		if (color[i] != UNCOLORED && color[i] == color[j]) {
	    			//cout << i << " " << j << endl;
	    			flag = false;
	    			return; 
	    		} else if (visited[j] == false) {
	    			color[j] = !color[i];	
	    			q.push(j);
	    		}
	    	}
		}
	}
}

bool vertexTwoColor(int n)
{
	bool bipartie = true;
	M(color, UNCOLORED);
	M(visited, 0);
	F(i,1,n+1)
		if (!visited[i]) {
			color[i] = BLUE;
			bfs(i, n, bipartie);
		}
	return bipartie;
}

int main()
{
	input();
	int t;
	int n, m;
	int x, y;
	S(t);
	//t = 1;
	F(i,0,t) {
		M(matrix, 0);
		bool flag;
		S(n), S(m);
		F(j,0, m) {
			S(x),S(y);
			matrix[x][y] = true;
			matrix[y][x] = true;
		}
		flag = vertexTwoColor(n);
		if (!flag) {
			cout << "Scenario #"<<i+1<<":\nSuspicious bugs found!\n";
		} else {
			cout << "Scenario #"<<i+1<<":\nNo suspicious bugs found!\n";
		}
	}
	return 0;
}