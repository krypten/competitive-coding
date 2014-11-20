/*
 *  Author		: Krypten
 *  Algorithm	: DP
 */

#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

#define INF 		INT_MAX
#define ull 		unsigned long long
#define ill 		long long int
#define pii 		pair<int,int>
#define pb(x) 		push_back(x)
#define F(i,a,n) 	for(int i=(a);i<(n);++i)
#define FI(i,a,n) 	for(i=(a);i<(n);++i)
#define FD(i,a,n) 	for(int i=(a);i>=(n);--i)
#define FE(it,x) 	for(it=x.begin();it!=x.end();++it)
#define V(x) 		vector<x>
#define S(x) 		scanf("%d",&x)
#define P(x) 		printf("%d ",x)
#define Sl(x) 		scanf("%llu",&x)
#define M(x,i) 		memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) 	((a)>(b)?(a):(b))

ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

int arr[100050][3];
int cost[100050][3];
int moves[][4] = {{1,0},{1,1},{0,1},{1,-1}};

int dp(int i, int j, int n)
{
	int x,y;
	
	if (i < 0 || i >= n || j < 0 || j > 2) {
		return INF/2;
	}
	if (i == (n-1) && j == 1) {
		return 0;
	}
	int& ans = cost[i][j];
	if (ans != -1)
		return ans;

	ans = INF/2;
	F(k,0,4) {
		x = i+moves[k][0]; y = j+moves[k][1];
		ans = min(ans,dp(x, y, n) + arr[x][y]);
	}
	return ans;
}

int main()
{
	int ctr, n;
	//scanf("%d", &t);
	ctr = 1;
	while (ctr) {
		cin >> n;
		if (n == 0)
			break;

		M(cost, -1); 
		F(i,0,n)
			S(arr[i][0]),S(arr[i][1]),S(arr[i][2]);

		cout << ctr << ". " << dp(0,1,n) + arr[0][1] << endl;
		ctr += 1;

		/*
		F(j,0,n)
			P(cost[j][0]),P(cost[j][1]),P(cost[j][2]), cout << "\n";
		*/
	}
	return 0;
}