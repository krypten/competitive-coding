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
#define Sf(x) 		scanf("%lf",&x)
#define Ss(x)		scanf("%s", x)
#define P(x) 		printf("%d",x)
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

int main()
{
	input();
	int t;
	int temp;
	int n, m;
	//S(t);
	t = 1;
	while (t--) {
		double a,b,c,d;
		Sf(a),Sf(b), Sf(c), Sf(d);
		int first = (int) max(3.0*a/10.0, a - (c*a/250.0));
		int second = (int) max(3.0*b/10.0, b - (d*b/250.0));
		if (first < second)
			Ps("Vasya\n");
		else if (first > second)
			Ps("Misha\n");
		else if (first == second)
			Ps("Tie\n");
	}
	return 0;
}
