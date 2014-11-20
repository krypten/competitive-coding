/*
 *  Author		: Krypten
 *  Algorithm	: DP + Bit masking
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
#define SIZE 32
#define DIRTY 10
int n, m;

typedef struct {
	int x;
	int y;
	int dirty;
	int depth;
} node;

int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int cnt;
char matrix[SIZE][SIZE];
bool visited[SIZE][SIZE][1<<DIRTY];

bool legalMove(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] != 'x')
		return true;
	return false;
}

int bfs(int sX, int sY)
{
	M(visited, false);
	queue<node> q;
	node v;
	v.x=sX; v.y = sY; v.dirty = 0; v.depth = 0;
	q.push(v);
	while (!q.empty()) {
		node u = q.front(); q.pop();
		//cout << u.x << " " << u.y << " " << u.depth << "\n";
		if (u.dirty == (1 << cnt) - 1)
            return u.depth;
        if (visited[u.x][u.y][u.dirty])
            continue;
        visited[u.x][u.y][u.dirty] = true;

		F(i,0,4) {
			int X = u.x + moves[i][0];
			int Y = u.y + moves[i][1];
			int D = u.dirty;
			if (legalMove(X, Y)) {
				v.x = X; v.y = Y; v.depth = u.depth + 1;
				//cout << "Pushing : " << v.x << " " << v.y << " " << v.depth << "\n";
				if (matrix[X][Y] >= '0' && matrix[X][Y] <= '9')
					D |= (1 << matrix[X][Y] - '0');
				v.dirty = D;
				q.push(v);
			}
		}
		//cout << u.x << " " << u.y << " " << u.depth << " " << q.size() << "\n";
	}
	return -1;
}

int main()
{
	input();
	int t;
	int a,b,limit;
	//S(t);
	t = 1;
	while (t) {
		S(m),S(n);
		if ( n == 0 && m == 0)
			break;
		cnt = 0;
		F(i,0,n)
			F(j,0,m) {
				scanf(" %c", &matrix[i][j]);
				if (matrix[i][j] == 'o')
					a = i, b = j;
				else if (matrix[i][j] == '*')
					matrix[i][j] = cnt++ + '0';
			}
		P(bfs(a,b)),Ps("\n");
	}
	return 0;
}
