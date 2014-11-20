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

int arr[512];

int main()
{
	int t, n,m,d;
	scanf("%d", &t);
	//t = 1;
	while (t--) {
		cin >> n >> m >> d;
		F(i,0,n)
			S(arr[i]);
		sort(arr, arr+n);
		int i = 0;
		while (m > 0 && i < n) {
			if (arr[i] > d) {
				m--;
				arr[i] -= d;
			} else {
				i++;
			}
		}
		if (m == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
