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

int dp[32][32];
int arr[32][32];

int solve(int i, int j, int n, int m)
{
	//cout << i << " " << j << endl;
	if (i == n-1 && j == m-1)
		return 0;
	if (i >= n || j >= m)
		return INF;
	int& ans = dp[i][j];
	if (ans != -1)
		return dp[i][j];
	ans = INF/2;

	ans = min (solve(i+1,j,n,m) + arr[i+1][j], solve(i,j+1,n,m) + arr[i][j+1]);
	return ans;
}

void fill(int n, int m)
{
	F(i,0,n+1)
		F(j,0,m+1)
			dp[i][j] = -1;
}

int main()
{
	input();
	int t;
	int n,m;
	int x,y;
	//S(t);
	t = 1;
	while (t--) {
		S(n),S(m);
		S(x),S(y);
		F(i,0,n)
			F(j,0,m)
				S(arr[i][j]);
		M(dp,-1);
		//fill(n, m);
		int ans = solve(x-1,y-1,n,m);
		//cout << ans << endl;
		if (arr[x-1][y-1] - ans >= 0)
			Ps("Y "),P(arr[x-1][y-1]- ans),Ps("\n");
		else
			Ps("N\n");
	}
	return 0;
}
