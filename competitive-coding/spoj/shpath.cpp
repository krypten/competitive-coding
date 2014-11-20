/*
 *  Author		: Krypten
 *  Algorithm	: Dijkstra
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
#define SIZE 10050
struct Comparator {
	bool operator() (const pii& a, const pii& b) {
		if (a.fr == b.fr)
			return a.se > b.se;
		return a.fr > b.fr;
	}
};

V(vector<pii> ) AdjList;
int dist[SIZE];
//bool visited[SIZE];
priority_queue<pii,V(pii),Comparator> pq;

void dijkstra(int source)
{
	dist[source] = 0;
	pq.push(pii(dist[source], source));
	while (!pq.empty()) {
		pii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		//cout << u <<  " " << d << "\n";
		if (d > dist[u])
			continue;   // this check is important
		F(j,0,(int)AdjList[u].size()) {
			pii v = AdjList[u][j];
			//cout << v.fr << " " << (dist[u] + v.se )<< " vs " << (dist[v.fr]) << "\n";
			if (dist[u] + v.se < dist[v.fr]) {
				dist[v.fr] = dist[u] + v.se;
				//parent[v.fr] = u;
				pq.push(pii(dist[v.fr], v.fr));
				//cout << "ADded :: " << v.fr << "\n";
			}

		}
	}
}

int main()
{
	input();
	int t;
	int p, n, m;
	int u, v, w;
	char temp[16];
	map<string,int> cities;
	S(t);
	//t = 1;
	while (t--) {
		S(n);
		//M(visited, false);
		AdjList.assign(n+1, V(pii)());
		F(i,0,n) {
			Ss(temp);
			string str(temp);
			cities.insert(pair<string,int>(str, i+1));
			S(m);
			F(j,0,m) {
				S(v), S(w);
				AdjList[i+1].pb(pii(v, w));
				AdjList[v].pb(pii(i+1, w));
			}
		}
		S(m);
		F(i,0,m) {
			M(dist, 0x33333333);
			Ss(temp);
			string str(temp);
			dijkstra((cities.find(str))->se);
			Ss(temp);
			str.assign(temp);
			P(dist[(cities.find(str))->se]),Ps("\n");
		}
	}
	return 0;
}
