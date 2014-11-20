/*
 *  Author		: Krypten
 *  Algorithm	: Adhoc
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

ill solve (int n)
{
	if (n/10 == 0) 
		return n*(n+1)/2;
	int i = 0;
	int m = n;
	while (m/10 > 0) {
		m /= 10;
		i++;
	}
	ill power = 1;
	int j = i;
	while (j--) {
		power *= 10;
	}
	return ((m*45*i*power/10) + m*(m-1)*power/2 + (n%power + 1) * m + solve(n%power));
}

int main()
{
	input();
	int t;
	int n, m;
	//S(t);
	t = 1;
	while (t) {
		S(n),S(m);
		if (n == -1 && m == -1)
			break;
		//cout << solve(m) << " " << solve(n-1) << endl;
		Pl(solve(m) - solve(n-1)),Ps("\n");
	}
	return 0;
}
