/*
 *  Author		: Krypten
 *  Algorithm	: DFS
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
#define LSOne(S) 	(S & (-S))

ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#	define se second

void input() {
#if !ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}


#define BLACK 1
#define WHITE -1

typedef vector <vector<int> > vii;

vii adjList;
int dfs_num[10050];
int total;

int dfs(int u) {
	int ans = 0;
	int cnt = 1;
	dfs_num[u] = BLACK;
	F(i,0,(int)adjList[u].size()) {
		if(dfs_num[adjList[u][i]] == WHITE ) {
			ans += dfs(adjList[u][i]);
			cnt++;
		}
	}
	ans += cnt;
	//cout << u << " " << ans << endl;
	total += ans;
	return ans;
}

int main()
{
	int t;
	int u, v;
	int n, m;


	S(t);
	while (t--) {
		S(n);
		total = 0;
		M(dfs_num, -1);
		adjList.assign(n, vector<int>());

		F(i,1,n) {
			S(u),S(v);
			adjList[u].pb(v);
			adjList[v].pb(u);
		}
		int ans = dfs(0);

		P(total),Ps("\n");
	}
	return 0;
}
