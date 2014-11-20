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
	int t, n;
	//scanf("%d", &t);
	t = 1;
	while (t--) {
		int temp;
		int sum = 0;
		int n = 10;
		bool flag = true;
		F(i,0,n) {
			S(temp);
			sum += temp;
			if (sum >=100 && flag) {
				if ((sum - 100) <= (100 + temp -sum)) {
					cout << sum << endl;
				} else {
					cout << sum-temp << endl;
				}
				flag = false;
			}
		}
		if (flag)
			cout << sum << endl;
	}
	return 0;
}
