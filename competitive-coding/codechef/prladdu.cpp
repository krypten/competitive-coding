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

pii vil[100005];
pii din[100005];

int main()
{
	input();
	int t;
	int n, m;
	S(t);
	//t = 1;
	while (t--) {
		S(n);
		int j = 0;
		int k = 0;
		F(i, 0 , n) {
			S(m);
			if (m > 0) {
				vil[j++] = pii(m,i);
			} else if (m!= 0) {
				din[k++] = pii(-m,i);
			}
		}
		int u = 0, v = 0;
		ill ans = 0;
		while (u < j && v < k) {
			if (vil[u].fr > din[v].fr) {
				ans = ans + din[v].fr * abs(vil[u].se - din[v].se);
				vil[u].fr = vil[u].fr - din[v].fr;
				din[v].fr = 0;
				v++;
				//cout << "First : " << ans << endl;
			} else {
				ans = ans + vil[u].fr * abs(din[v].se - vil[u].se);
				din[v].fr = din[v].fr - vil[u].fr;
				vil[u].fr = 0;
				u++;
				if (din[v].fr == 0) {
					v++;
				}
				//cout << "Second : " << ans << endl;
			}
		}
		Pl(ans), Ps("\n");
	}
	return 0;
}