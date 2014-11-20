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

ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

void input() {
#if !ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}

ill gcd(ill a, ill b)
{
	if (a%b==0)
		return b;
	return gcd(b, a%b);
}

int main()
{
	input();
	string s;
	while (1) {
		cin >> s;
		if (s[0] == '*')
			break;
		ill ans = 1;
		if (s[0] == 'N')
			ans = 0;
		int len = s.size();
		V(ill) yes;
		V(ill) no;
		int i;
		bool flag = false;
		FI(i,1,len+1) {
			//cout << i << endl;
			if (s[i-1] == 'Y') {
				ans = (ans * (ill)i)/ gcd(ans,(ill)i);
				yes.push_back((ill)i);
				for(V(ill)::iterator it = no.begin(); it!= no.end(); it++) {
					if (i % *it == 0) {
						//cout << " error @ " << *it << endl;
						flag = true;
						break;
					}
				}
				if (flag)
					break;
			} else {
				no.push_back(i);
				bool interupt = false;
				bool cnt = false;
				if (gcd(ans, (ill)i) == (ill)i) {
					flag = true;
				}
				if (flag)
					break;
			}
		}
		if (flag) {
			Ps("-1\n");
		} else {
			Pl(ans), Ps("\n");
		}
	}
	return 0;
}
