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
#define SIZE 1000
int n, m;

bool legalMove(int x, int y)
{
	if (x > 0 && x <= n && y > 0 && y <= m) {
		return true;
	}
	return false;
}

int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool visited[SIZE][SIZE];
int matrix[SIZE][SIZE];

typedef struct {
	int x;
	int y;
	int depth;
} node;

struct comparator {
	bool operator()(const node& a, const node& b) {
		return a.depth > b.depth;
	}
};
int ucs(int sX, int sY, int dX, int dY, int limit)
{
	M(visited, false);
	priority_queue<node, vector<node>, comparator> pq;
	node v;
	v.x=sX; v.y = sY; v.depth = matrix[sX][sY];
	pq.push(v);
	while (!pq.empty()) {
		node u = pq.top(); pq.pop();
		//cout << u.x << " " << u.y << " " << u.depth << "\n";
		if (u.x == dX && u.y == dY) {
			return u.depth;
		}
		if (visited[u.x][u.y])
			continue;
		visited[u.x][u.y] = true;
		if (u.depth > limit)
			continue;
		//cout << u.x << " " << u.y << " " << u.depth << "\n";
		F(i,0,4) {
			int X = u.x + moves[i][0];
			int Y = u.y + moves[i][1];
			if (legalMove(X, Y) && !visited[X][Y]) {
				node v; v.x = X; v.y = Y; v.depth = u.depth + matrix[X][Y];
				//cout << "Pushing : " << v.x << " " << v.y << " " << v.depth << "\n";
				pq.push(v);
			}
		}
		//cout << u.x << " " << u.y << " " << u.depth << " " << pq.size() << "\n";
	}
	return 0;
}

int main()
{
	input();
	int t;
	int a,b,limit;
	S(t);
	//t = 1;
	while (t--) {
		S(n),S(m);
		int ans;
		F(i,1,n+1)
			F(j,1,m+1)
				S(matrix[i][j]);

		S(a),S(b),S(limit);
		if ((ans = ucs(1,1,a,b,limit)) <= limit)
			Ps("YES\n"),P(limit-ans), Ps("\n");
		else
			Ps("NO\n");
	}
	return 0;
}
