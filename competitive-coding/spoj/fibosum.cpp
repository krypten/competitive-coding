/*
 *  Author		: Krypten
 *  Algorithm	: Fibonacci matrix
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
#define Sl(x) 		scanf("%llu",&x)
#define Pl(x) 		printf("%lld\n",x)
#define M(x,i) 		memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) 	((a)>(b)?(a):(b))

ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

#define MOD 1000000007

void multiply(ill F[2][2], ill M[2][2])
{
	ill	x = (F[0][0]*M[0][0] + F[0][1]*M[1][0]) % MOD;
	ill y = (F[0][0]*M[0][1] + F[0][1]*M[1][1]) % MOD;
	ill z = (F[1][0]*M[0][0] + F[1][1]*M[1][0]) % MOD;
	ill w = (F[1][0]*M[0][1] + F[1][1]*M[1][1]) % MOD;
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}
void power(ill F[2][2], ill n)
{
	if( n == 0 || n == 1)
		return;
	ill M[2][2] = {{1,1},{1,0}};
	power(F, n/2);
	multiply(F, F);
	
	if (n%2 != 0)
		multiply(F, M);
}

ill fib_logn(ill n)
{
	ill F[2][2] = {{1,1},{1,0}};
	if (n == 0)
		return 0;
	power(F, n-1);
	return F[0][0];
}

int main()
{
	int t;
	scanf("%d", &t);
	//t = 1;
	while (t--) {
		ill n,m;
		cin >> n >> m;
		if (m < n) {
			int t = m;n = m; m = t;
		}
		ill ans = (fib_logn(m+2)-1-(fib_logn(n+1)-1)) % MOD;
		if(ans<0)
			ans += MOD;
		ans = ans % MOD;
		Pl(ans);
	}
	return 0;
}