/*
 *  Author		: Krypten
 *  Algorithm	: Recursion
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
//int cnt = 0;
char str[32];

int solve (int i, int n, int prev, int current)
{
	int temp;
	int ans = 0;
	if (i == n) {
		//cnt++;
		return (prev <= current);
	}
	if (current >= prev) {
		temp = solve(i + 1, n, current, str[i]-'0');
		ans+= (temp);
	}
	temp = solve(i + 1, n, prev, current + str[i]-'0');
	ans += (temp);
	return ans;
}

int main()
{
	input();
	int t;
	int n, m;
	//S(T);
	t = 0;
	while (++t) {
//		cnt = 0;
		Ss(str);
		if (strcmp(str, "bye") == 0)
			break;
		n = strlen(str);
		printf("%d. %d\n", t,solve(1,n,0,str[0]-'0'));
		//P(cnt),Ps("\n");	
	}
	return 0;
}
