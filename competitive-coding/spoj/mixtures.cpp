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

ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

void input() {
#if !ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}

#define SIZE 128

int arr[SIZE][SIZE];
int dp[SIZE][SIZE];

int solve(int beg, int end)
{
	if (beg == end)
		return 0;
	if (end - beg == 1)
		return arr[beg][beg]*arr[end][end];
	int &ans = dp[beg][end];
	if (ans != -1)
		return dp[beg][end];

	ans = INF;
	F(i,beg,end)
		ans = min(ans, arr[beg][i] * arr[i+1][end] + solve(beg, i) + solve(i+1, end));

	return ans;
}

int main()
{
	input();
	int t, n, m;

	while (S(t) != -1) {
		F(i,0,t)
			S(arr[i][i]);
		F(i,0,t)
			F(j,i+1,t) {
				arr[i][j] = arr[i][j-1] + arr[j][j];
				if (arr[i][j] >= 100)
					arr[i][j] -= 100;
			}
		M(dp, -1);
		cout << solve(0, t-1) << endl;
	}
	return 0;
}
