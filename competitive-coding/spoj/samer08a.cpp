/*
 *  Author		: Krypten
 *  Algorithm	: Dijkstra
 */

#include <queue>
#include <vector>
#include <iostream>
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
#define SIZE 512
struct Comparator {
	bool operator() (const pii& a, const pii& b) {
		if (a.fr == b.fr)
			return a.se > b.se;
		return a.fr > b.fr;
	}
};

V(vector<pii> ) AdjList;
V(vector<pii> ) AdjListR;
int dist[SIZE];
int distR[SIZE];
int parent[SIZE];
bool deleted[SIZE][SIZE];

void dijkstra(int source)
{
	M(dist, 0x33333333);
	dist[source] = 0;
	priority_queue<pii,V(pii),Comparator> pq;
	pq.push(pii(dist[source], source));
	while (!pq.empty()) {
		pii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		//cout << u <<  " " << d << " " << dist[u] << "\n";
		if (d > dist[u])
			continue;   // this check is important
		F(j,0,(int)AdjList[u].size()) {
			pii v = AdjList[u][j];
			if (deleted[u][v.fr])
				continue;

			//cout << v.fr << " " << (dist[u] + v.se )<< " vs " << (dist[v.fr]) << "\n";
			if (dist[u] + v.se < dist[v.fr]) {
				dist[v.fr] = dist[u] + v.se;
				parent[v.fr] = u;
				pq.push(pii(dist[v.fr], v.fr));
				//cout << "ADded :: " << v.fr << "\n";
			}
		}
	}
}

void dijkstraReverse(int destination)
{
	priority_queue<pii,V(pii),Comparator> pq;
	M(distR, 0x33333333);
	distR[destination] = 0;
	pq.push(pii(distR[destination], destination));
	while (!pq.empty()) {
		pii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		//cout << u <<  " " << d << "\n";
		if (d > distR[u])
			continue;   // this check is important
		F(j,0,(int)AdjListR[u].size()) {
			pii v = AdjListR[u][j];

			//cout << v.fr << " " << (distR[u] + v.se )<< " vs " << (distR[v.fr]) << "\n";
			if (distR[u] + v.se < distR[v.fr]) {
				distR[v.fr] = distR[u] + v.se;
//				parent[v.fr] = u;
				pq.push(pii(distR[v.fr], v.fr));
				//cout << "ADded :: " << v.fr << "\n";
			}
		}
	}
}
void removeEdge(int u, int v)
{
	//cout << "removing " << u << " " << v << "\n";
	for (vector<pii>::iterator it = AdjList[u].begin();it != AdjList[u].end(); ++it) {
		if (it->fr == v) {
			AdjList[u].erase(it);
			break;
		}
	}
}

void printPath(int s, int d)
{
	int i = d;
	while (i != s || parent[i] != s) {
		P(i),Ps(" -> ");
		i = parent[i];
	}
	P(s);
	Ps("\n");
	return ;
}

void removeSingleShortestPath(int s, int d)
{
	int i = d;
	while (i != s) {
		deleted[parent[i]][i] = true;
		//removeEdge(parent[i], i);
		i = parent[i];
	}
	return ;
}

void removeMultipleShortestPath(int s, int d)
{
	int i;
	dijkstraReverse(d);
	queue<int> q;
	q.push(d);
	while (!q.empty()){
		i = q.front(); q.pop();
		if (i == s)
			continue;
		//cout << "\t" << i << "\n";
		F(j,0,(int)AdjListR[i].size()) {
			int u = AdjListR[i][j].fr;
			//cout << u << " " << dist[u] << " " << distR[u] << " " << dist[d] << "\n";
			if (dist[u] + distR[u] == dist[d] && !deleted[u][i]) {
				//cout << "removing " << u << " " << i << "\n";
				deleted[u][i] = true;
				q.push(u);
			}
		}
	}
}


int main()
{
	input();
	int t;
	int n, m;
	int s, d;
	int u, v, w;
	//S(t);
	t = 1;
	while (t) {
		S(n), S(m);
		if (n == 0 && m == 0)
			break;
		S(s), S(d);
		AdjList.assign(n+1, V(pii)());
		AdjListR.assign(n+1, V(pii)());
		F(i,0,m) {
			S(u), S(v), S(w);
			AdjList[u].pb(pii(v, w));
			AdjListR[v].pb(pii(u,w));
		}

		if (s == d) {
			Ps("-1\n");continue;
		}

		M(deleted, false);
		dijkstra(s);
		//Ps(" night path : ");printPath(s, d);
		if (dist[d] > 10000000) {
			Ps("-1\n");
			continue;
		}

		removeMultipleShortestPath(s, d);
		dijkstra(s);
		//cout << " Ans : ";
		if (dist[d] > 10000000)
			Ps("-1\n");
		else
			P(dist[d]),Ps("\n");
	}
	return 0;
}