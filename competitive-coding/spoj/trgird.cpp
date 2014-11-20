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



int main()
{
	int t, n, m;
	scanf("%d", &t);
	//t = 1;
	while (t--) {
		cin >> n >> m;
		char ans = 'R';
		if (n > m) {
			if (m % 2 == 1) {
				ans = 'D';
			} else {
				ans = 'U';
			}
		} else {
			if (n % 2 == 1) {
				ans = 'R';
			} else {
				ans = 'L';
			}
		}
		cout << ans << endl;
	}
	return 0;
}
