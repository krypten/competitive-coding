/*
 *  Author		: Krypten
 *  Algorithm	: uniform Cost Search
 */
#include <iostream>
#include <queue>
#include <vector>
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
// Logic
#define SIZE 8
int n, m;

bool legalMove(int x, int y)
{
	if (x >= 0 && x <= SIZE && y >= 0 && y < SIZE) {
		return true;
	}
	return false;
}

int moves[SIZE][2] = {{2, 1}, {1, 2}, {2, -1}, {1, -2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
bool visited[SIZE][SIZE];

typedef struct {
	int x;
	int y;
	int cost;
} node;

struct comparator {
	bool operator()(const node& a, const node& b) {
		return a.cost > b.cost;
	}
};
int ucs(int sX, int sY, int dX, int dY)
{
	M(visited, false);
	priority_queue<node, vector<node>, comparator> pq;
	node v;
	v.x=sX; v.y = sY; v.cost = 0;
	pq.push(v);
	while (!pq.empty()) {
		node u = pq.top(); pq.pop();
		//cout << u.x << " " << u.y << " " << u.cost << "\n";
		if (u.x == dX && u.y == dY) {
			return u.cost;
		}
		if (visited[u.x][u.y])
			continue;
		visited[u.x][u.y] = true;

		//cout << u.x << " " << u.y << " " << u.cost << "\n";
		F(i,0,SIZE) {
			int X = u.x + moves[i][0];
			int Y = u.y + moves[i][1];
			if (legalMove(X, Y) && !visited[X][Y]) {
				node v; v.x = X; v.y = Y; v.cost = u.cost + (u.x * X + u.y * Y);
				//cout << "Pushing : " << v.x << " " << v.y << " " << v.cost << "\n";
				pq.push(v);
			}
		}
		//cout << u.x << " " << u.y << " " << u.cost << " " << pq.size() << "\n";
	}
	return -1;
}

int main()
{
	input();
	int t;
	int a,b,c,d;
	//S(t);
	//t = 1;
	while (scanf("%d %d %d %d",&a,&b,&c,&d) != EOF) {
		int ans = ucs(a,b,c,d);
		if (ans == -1)
			Ps("-1\n");
		else
			P(ans), Ps("\n");
	}
	return 0;
}
