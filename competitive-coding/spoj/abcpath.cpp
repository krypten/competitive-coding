/*
 *  Author		: Krypten
 *  Algorithm	: Dynamic Programming
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
#define SIZE 90
int n, m;
int moves[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
bool visited[SIZE][SIZE];
char matrix[SIZE][SIZE];

typedef struct {
	int x;
	int y;
	int depth;
} node;


bool legalMove(int x, int y)
{
	if (x > 0 && x <= n && y > 0 && y <= m) {
		return true;
	}
	return false;
}

int bfs(int sX, int sY)
{
	M(visited, false);
	queue<node> pq;
	node v;
	int ans = 0;
	v.x=sX; v.y = sY; v.depth = 1;
	pq.push(v);
	while (!pq.empty()) {
		node u = pq.front(); pq.pop();
		//cout << u.x << " " << u.y << " " << u.depth << "\n";
		if (visited[u.x][u.y])
			continue;
		visited[u.x][u.y] = true;

		ans = max(ans, u.depth);
		//cout << u.x << " " << u.y << " " << u.depth << "\n";
		F(i,0,8) {
			int X = u.x + moves[i][0];
			int Y = u.y + moves[i][1];
			if (legalMove(X, Y) && !visited[X][Y] && ((matrix[X][Y] - matrix[u.x][u.y]) == 1)) {
				node v; v.x = X; v.y = Y; v.depth = u.depth + 1;
				//cout << "Pushing : " << v.x << " " << v.y << " " << v.depth << "\n";
				pq.push(v);
			}
		}
		//cout << u.x << " " << u.y << " " << u.depth << " " << pq.size() << "\n";
	}
	return ans;
}

int main()
{
	input();
	int t;
	int a,b,limit;
	//S(t);
	t = 0;
	while (++t) {
		S(n),S(m);
		int ans = 0;
		if (n == 0 && m == 0)
            break;
		F(i,1,n+1)
			F(j,1,m+1) {
				scanf(" %c", &matrix[i][j]);
			}

		F(i,1,n+1)
			F(j,1,m+1)
				if(matrix[i][j] == 'A')
					ans = max(ans, bfs(i,j));

		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}
