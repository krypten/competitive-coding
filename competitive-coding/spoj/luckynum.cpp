/*
 *  Author		: Krypten
 *  Algorithm	: BFS
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
#	define se second

void input() {
#if !ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}

// Logic
//#define pip pair<int, pii >
typedef struct {
	//int position;
	int eight;
	int six;
	int rem;
	bool flag;
} node;

int remainder8(int len, int prevRem, int mod)
{
	int val = 8;
	while (len--) {
		val = (val * 10)%mod;
	}
	return (val + prevRem)%mod;
}

pii bfs(int n)
{
	queue <node > q;
	node v;

	v.eight = 0; v.six = 1; v.rem = 6%n;v.flag =false;
	q.push(v);
	v.eight = 1; v.six = 0; v.rem = 8%n;v.flag =true;
	q.push(v);

	while(!q.empty()) {
		node u = q.front(); q.pop();
		if (u.rem % n == 0) {
			return pii(u.eight, u.six);
		}
		v.eight = u.eight; v.six = u.six + 1; v.rem = (u.rem*10+6)%n; v.flag = false;
		q.push(v);
		if (u.flag) {
			v.eight = u.eight + 1; v.six = u.six; v.rem = remainder8(u.eight + u.six, u.rem, n); v.flag = true;
			q.push(v);
		}
	}
	return pii(-1,-1);
}

void printPath(int i, int j)
{
	while (i-- > 0)
		Ps("8");
	while (j-- > 0)
		Ps("6");
	Ps("\n");
}

int main()
{
	input();
	int t;
	int n, m;
	S(t);
	//t = 1;
	while (t--) {
		S(n);
		if (n%5 == 0) {
            Ps("-1\n");continue;
        }
		pii i = bfs(n);
		// path
		//debug(j,100,path);
		if (i.fr != -1)
            printPath(i.fr, i.se);
        else
            Ps("-1\n");
	}
	return 0;
}
