/*
 *  Author		: Krypten
 *  Algorithm	: Vertex Cover (Dynamic Programming)
 */

#include <iostream>
#include <queue>
#include <vector>
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
#define se second

void input() {
#if !ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}
// Logic
#define SIZE 100050

V( V(int)) adjList;

int dp[SIZE][2];

int solve(int cur, int parent, bool parentCovered, int n)
{
    int& ans = dp[cur][parentCovered];
    if (ans != -1)
        return ans;
    ans = 1;
    int temp = 0;
    if (parentCovered) {
        F(i,0, (int)adjList[cur].size())
            if (adjList[cur][i] != parent)
                temp += solve(adjList[cur][i], cur, false, n);

        F(i,0, (int)adjList[cur].size())
            if (adjList[cur][i] != parent)
                ans += solve(adjList[cur][i], cur, true, n);

        ans = min(ans,temp);
    } else {
        F(i,0, (int)adjList[cur].size())
            if (adjList[cur][i] != parent)
                ans += solve(adjList[cur][i], cur, true, n);
    }
    return ans;
}

int main()
{
	input();
	int t;
	int n;
	int a,b;
	//S(t);
	t = 1;
	while (t--) {
		S(n);
		int ans;
		adjList.assign(n+1, V(int)());
		F(i,0,n-1) {
			S(a),S(b);
			adjList[a].pb(b);
			adjList[b].pb(a);
		}
        M(dp, -1);
        int result1 = 0;
        F(i,0, (int)adjList[1].size())
            result1 += solve(adjList[1][i], 1, false, n);

        int result2 = 1;
        F(i,0, (int)adjList[1].size())
            result2 += solve(adjList[1][i], 1, true, n);

        P(min(result1, result2)), Ps("\n");
	}
	return 0;
}
