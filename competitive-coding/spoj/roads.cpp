/*
 *  Author		: Krypten
 *  Algorithm	: DP
 */

#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

#define INF 100000
#define ONLINE_JUDGE 1

#define ull 		unsigned long long
#define ill 		long long int
#define pii 		pair<int,int>
#define pip 		pair<int,pii >
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
#define MAX(a,b) 	((a)>-(b)?(a):(b))
#define MIN(a,b) 	((a)>(b)?(b):(a))
#define LSOne(S) 	(S & (-S))

ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

void input() {
#if !ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}

#define TIME 10001
#define SIZE 128

int tollArr[SIZE][SIZE];
int pathLength[SIZE][SIZE];
int dp[SIZE][TIME];
V(vector<pip >) adjList;
int limit_time;

int solve(int i, int limit, int n)
{
    //cout << i << " " << limit << "\n";
	int& ans = dp[i][limit];
	if (i == n)
		return 0;
	if (limit < 0)
		return INF;
	if (ans != -1)
		return ans;
	ans = INF;
	F(j, 0 , int(adjList[i].size())) {
		pip tmp = adjList[i][j];
		if (i != tmp.fr && limit >= tmp.se.se)
            ans = min(ans, solve(tmp.fr, limit - tmp.se.se, n) + tmp.se.fr);
	}
    //cout << i << " " << limit << " : " <<r ans << "\n";
	return ans;
}

int main()
{
	input();
	int t;
	int n, m;
    int u, v;
    int l, to;
	S(t);
	//t = 1;
	while (t--) {
		S(limit_time), S(n);
		S(m);
		M(pathLength, 0x33333333);
		adjList.assign(n+1, V(pip)());
		F(i, 0 , m) {
			S(u); S(v);S(l),S(to);
			adjList[u].pb(pip(v, pii(l,to)));
		}
		/*F(i,1,n+1) {
            debug(j,n+1,pathLength[i]);
            Ps("\n");
		}*/

		M(dp,-1);
		int ans = solve(1, limit_time,n);
		if (ans == INF)
			Ps("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
