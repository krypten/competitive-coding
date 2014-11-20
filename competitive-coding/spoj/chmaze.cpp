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
#define SIZE 5

int moves[SIZE][2] = {{0, 0}, {0, 1}, {-1, 0}, {1, 0}, {0, 1}};
bool matrix[32][32][32];
bool visited[32][32][32];

typedef struct {
	int x;
	int y;
	int p; 		// pattern no.
	int depth;
} node;

int n, m, p;

bool legalMove(int x, int y, int p)
{
	if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y][p]) {
		return true;
	}
	return false;
}

int bfs(int sx, int sy, int dx, int dy)
{
	node v;
	queue<node> q;
	M(visited, false);
	v.x = sx;
	v.y = sy; v.depth = 0; v.p = 0;
	q.push(v);
	while (!q.empty()) {
		//cout << "Entering \n";
		node u = q.front(); q.pop();
		//cout << u.x << " " << u.y << " " << u.p << " " << u.depth << " " ;//<< matrix[u.x][u.y][u.p] << "\n";

		if (u.x == dx && u.y == dy) {
			return u.depth;
		}
		if (visited[u.x][u.y][u.p]) // equal # of mirrors with different incoming dir, got a WA for missing this
			continue;
		visited[u.x][u.y][u.p] = true;

		//cout << u.x << " " << u.y << " " << u.cost << "\n";
		F(i,0,SIZE) {
			int X = u.x + moves[i][0];
			int Y = u.y + moves[i][1];
			int P = (u.p + 1) % p;
				if (legalMove(X, Y, P)) { 
				v.x = X; v.y = Y; v.depth = u.depth + 1; v.p = P;
				//cout << "Pushing : " << v.x << " " << v.y << " " << v.cost << "\n";
				q.push(v);
			}
		}
		//cout << u.x << " " << u.y << " " << u.p <<  " " << u.depth << "\n";
	}
	return -1;
}

int main()
{
	input();
	int t;
	char temp;
	//S(t);
	t = 0;
	while (++t) {
		S(n), S(m), S(p);//, scanf(" %*c");
		if (n == 0 && m == 0 && p == 0)
			break;
		F(k,0, p)
		F(i, 0, n)
			F(j , 0, m) {
				cin >> temp;
				matrix[i][j][k] = (temp=='0'?true: false);
			}

		int ans = bfs(0,0, n-1,m-1);
		printf("Case %d: Luke and Leia can", t);
		if (ans == -1)
			Ps("not escape.\n");
		else {
			Ps(" escape in "), P(ans), Ps(" steps.\n");
		}

	}
	return 0;
}