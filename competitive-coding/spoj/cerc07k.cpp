/*
 *  Author		: Krypten
 *  Algorithm	: BFS + Bit masking
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
#define SIZE 128
#define KEYS 4

#define RED 1
#define BLUE 2
#define GREEN 4
#define YELLOW 8

int n, m;

typedef struct {
	int x;
	int y;
	int keys;
	int depth;
} node;

int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int cnt;
char matrix[SIZE][SIZE];
bool visited[SIZE][SIZE][16];

bool legalMove(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] != '#')
		return true;
	return false;
}

bool updateMatrixKeys(node& u, node& v)
{
	switch(matrix[v.x][v.y]) {
		case 'r' :	{v.keys = u.keys | RED; return  true;}
		case 'b' :  {v.keys = u.keys | BLUE; return true;}
		case 'g' :  {v.keys = u.keys | GREEN; return true;}
		case 'y' :  {v.keys = u.keys | YELLOW; return true;}
		case 'R' :  {if (u.keys & RED) return true; break;}
		case 'B' :  {if (u.keys & BLUE) return true; break;}
		case 'G' :  {if (u.keys & GREEN) return true; break;}
		case 'Y' :  {if (u.keys & YELLOW) return true; break;}
		default : return true;
	}
	return false;
}

int bfs(int sX, int sY)
{
	M(visited, false);
	queue<node> q;
	node v;
	v.x=sX; v.y = sY; v.keys = 0; v.depth = 0;
	q.push(v);
	while (!q.empty()) {
		node u = q.front(); q.pop();
		//cout << u.x << " " << u.y << " " << u.depth << " "  << u.keys << " " << matrix[u.x][u.y] << "\n";
		if (matrix[u.x][u.y] == 'X')
            return u.depth;
        if (visited[u.x][u.y][u.keys])
            continue;
        visited[u.x][u.y][u.keys] = true;

		F(i,0,4) {
			int X = u.x + moves[i][0];
			int Y = u.y + moves[i][1];

			if (legalMove(X, Y)) {
				v.x = X; v.y = Y; v.depth = u.depth + 1; v.keys = u.keys;
				//cout << "Pushing : " << v.x << " " << v.y << " " << v.depth << "\n";
				if (updateMatrixKeys(u, v))
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
	int a,b,dx,dy;
	//S(t);
	t = 1;
	while (t) {
		S(n),S(m);
		if ( n == 0 && m == 0)
			break;
		cnt = 0;
		F(i,0,n)
			F(j,0,m) {
				scanf(" %c", &matrix[i][j]);
				if (matrix[i][j] == '*')
					a = i, b = j;
			}
		int ans = bfs(a, b);
		if (ans == -1)
			Ps("The poor student is trapped!\n");
		else
			printf("Escape possible in %d steps.\n", ans);
	}
	return 0;
}
