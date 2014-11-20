/*
 *  Author		: Krypten
 *  Algorithm	: Minimum Spanning Tree
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

//  Logic Starts here
#define SIZE 10001
struct Comparator {
	bool operator() (const pii& a, const pii& b) {
		if (a.fr == b.fr)
			return a.se > b.se;
		return a.fr > b.fr;
	}
};

vector<pii> AdjList[SIZE];
bool visited[SIZE];
priority_queue<pii,V(pii),Comparator> pq;

/*
 * Parameter	:  Source Vertex
 * Return 		:  Minimum Cost Spanning Tree
 */

int prim(int source)
{
	int mstCost = 0;
	pq.push(pii(0, source));
	while (!pq.empty()) {
		pii u = pq.top(); pq.pop();

		//cout << u.fr << " " << u.se << "\n" ;
		if(visited[u.se])
			continue;
		visited[u.se] = true;

		mstCost += u.fr;
		F(j,0,(int)AdjList[u.se].size()) {
			pii v = AdjList[u.se][j];
			if (!visited[v.fr])
				pq.push(pii(v.se, v.fr));
		}
	}
	return mstCost;
}

int main()
{
	input();
	int t;
	int p, n, m;
	int u, v, w;
	S(t);
	//t = 1;
	while (t--) {
		S(n);
		M(visited, false);
		F(i,0,n) AdjList[i].clear();
		F(i,0,n) {
			scanf("%*s");
			S(m);
			F(j,0,m) {
				S(v), S(w);
				AdjList[i].pb(pii(v-1, w));
				AdjList[v-1].pb(pii(i, w));
			}
		}
		int ans = prim(0);
		P(ans),Ps("\n");
	}
	return 0;
}
