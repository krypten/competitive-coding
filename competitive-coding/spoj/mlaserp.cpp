/*
 *  Author		: Krypten
 *  Algorithm	: BFS
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
#define SIZE 4

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int moves[SIZE][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
char matrix[128][128];
int visited[128][128];

typedef struct {
	int x;
	int y;
	int dir;
	int mirror;
} node;

int n, m;

bool legalMove(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] != '*') {
		return true;
	}
	return false;
}

int isSamePath(int i, int j)
{
	if (i == j)
		return 0;
	return 1;
}

struct comparator {
	bool operator()(const node& a, const node&b) {
		return a.mirror > b.mirror;
	}	
};
int bfs(node s, node d)
{
	node v;
	queue<node> q;
	//priority_queue<node, V(node), comparator> q;
	M(visited, 0x333333);
	s.mirror = 0;
	s.dir = -1;
	d.mirror = 0x333332;
	q.push(s);
	while (!q.empty()) {
		node u = q.front(); q.pop();
		//cout << u.x << " " << u.y << " " << u.dir << " " << u.mirror << " " << matrix[u.x][u.y] << "\n";
		if (u.x == d.x && u.y == d.y) {
			(d.mirror = min(d.mirror, u.mirror));
			continue;
		}
		if (u.mirror > visited[u.x][u.y]) // equal # of mirrors with different incoming dir, got a WA for missing this
			continue;
		else
			visited[u.x][u.y] = u.mirror;

		//cout << u.x << " " << u.y << " " << u.cost << "\n";
		F(i,0,SIZE) {
			int X = u.x + moves[i][0];
			int Y = u.y + moves[i][1];

			if (legalMove(X, Y)) {
				v.x = X; v.y = Y; v.mirror = u.mirror + isSamePath(u.dir, i);
				//cout << "Pushing : " << v.x << " " << v.y << " " << v.cost << "\n";
				v.dir = i;
				q.push(v);
			}
		}
		//cout << u.x << " " << u.y << " " << u.cost << " " << pq.size() << "\n";
	}
	return (d.mirror != 0x333332)?d.mirror:0;
}

int main()
{
	input();
	int t;
	node arr[2];
	//S(t);
	t = 1;
	while (t--) {
		S(m), S(n);
		int cnt = 0;
		F(i, 0, n)
			F(j , 0, m) {
				scanf(" %c", &matrix[i][j]);
				if (matrix[i][j] == 'C') {
					arr[cnt].x = i, arr[cnt].y = j; ++cnt;
				}
			}

		P(bfs(arr[0], arr[1]) - 1), Ps("\n");

	}
	return 0;
}