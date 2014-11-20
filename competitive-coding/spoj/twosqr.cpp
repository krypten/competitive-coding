/*
 *  Author		: Krypten
 *  Algorithm	: Number Theory
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

int main()
{
	input();
	ill t, n;
	Sl(t);
	//t = 1;
	while (t--) {
		bool flag = true;
		Sl(n);
		//Pl(n),Ps("\n");
		for (ill i = 2; i * i <= n; i++) {
			int cnt = 0;
			while (n%i==0) {
				n = n/i;
				cnt++;
			}
			if (i%4 == 3 && cnt > 0 && cnt%2 == 1) {
				flag = false;
			}
			//Pl(n),Ps(" "),P(i),Ps(" "),P(cnt),Ps("\n");
		}
		if (n % 4 == 3) {
			flag = false;
		}
		if (flag) {
			Ps("Yes\n");
		} else {
			Ps("No\n");
		}
	}
	return 0;
}