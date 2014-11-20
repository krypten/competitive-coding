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
#define Sl(x) 		scanf("%llu",&x)
#define M(x,i) 		memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) 	((a)>(b)?(a):(b))

ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

int arr[16][128];

int dp(int n, int k)
{
	int& ans = arr[n][k];
	if (k == 0) {
		return (ans = 1);
	}
	if (n < 1) {
		return (ans = 0);
	}
	if (ans != -1) {
		return ans;
	}
	ans = 0;
	F(i,0,min(n,k + 1)) {
		ans = ans  + dp(n-1, k-i);
	}
	return ans;
}

int main()
{
	int t, n, k;
	scanf("%d", &t);
	//t = 1;
	//dp(12,64);
	while (t--) {
		cin >> n >> k;
		M(arr, -1);
		/*F(j,0,k+1) {
			F(i,0,n+1)		
				cout << arr[i][j] << " ";
			cout << "\n";
		}*/
		cout << dp(n, k) << "\n";
	}
	return 0;
}