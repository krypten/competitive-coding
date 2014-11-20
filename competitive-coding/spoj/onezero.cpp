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
#define SIZE 100000000
static bool path[SIZE];

int bfs(int n)
{
	queue <pii> q;
	q.push(pii(1,1));
	path[1] = true;
	while(! q.empty()) {
		pii u = q.front(); q.pop();
		if (u.se % n == 0) {
			return u.fr;
		}
		path[2*u.fr] = false;
		path[2*u.fr + 1] = true;
		q.push(pii(2*u.fr, (u.se*10)%n));
		q.push(pii(2*u.fr + 1, (u.se*10 + 1)%n));
	}
}

void printPath(int i)
{
	if (i <= 0)
		return ;
	printPath(i/2);
	if (path[i])
		Ps("1");
	else
		Ps("0");
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
		int i = bfs(n);
		// path
		//debug(j,100,path);
		printPath(i);
		Ps("\n");
	}
	return 0;
}