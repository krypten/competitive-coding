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

int moves[SIZE][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int matrix[128][128];
bool visited[128][128];

typedef struct {
	int x;
	int y;
	int val;
} node;

bool legalMove(int x, int y, int n)
{
	if (x >= 0 && x < n && y >= 0 && y < n) {
		return true;
	}
	return false;
}

int bfs(int sX, int sY, int n)
{
	int ans = 0;
	int dest = matrix[sX][sY];
	
	node v;
	v.x=sX; v.y = sY; v.val = matrix[sX][sY];
	
	queue<node> q;
	q.push(v);
	while (!q.empty()) {
		node u = q.front(); q.pop();
		//cout << u.x << " " << u.y << " " << u.cost << "\n";
		if (u.val != dest) {
			continue;
		}
		if (visited[u.x][u.y])
			continue;
		visited[u.x][u.y] = true;
		++ans;
		//cout << u.x << " " << u.y << " " << u.cost << "\n";
		F(i,0,SIZE) {
			int X = u.x + moves[i][0];
			int Y = u.y + moves[i][1];
			int V = matrix[X][Y];
			if (legalMove(X, Y, n) && !visited[X][Y] && V == dest) {
				node v; v.x = X; v.y = Y; v.val = V;
				//cout << "Pushing : " << v.x << " " << v.y << " " << v.cost << "\n";
				q.push(v);
			}
		}
		//cout << u.x << " " << u.y << " " << u.cost << " " << pq.size() << "\n";
	}
	return ans;
}

int main()
{
	input();
	int n;
	int u, v;
	//S(t);
	//t = 1;
	while (scanf("%d", &n) != EOF && n) {
		M(matrix,n);
		F(i, 1, n) {
			F(j , 0, n) {
				S(u),S(v);
				matrix[u-1][v-1] = i;
				if(n == j+1)
					while(getchar()!='\n');; 
			}

		}

		int cnt;
		bool flag = true;
		M(visited, false);	
		for (int i = 0; i < n && flag ; ++i) {
			F(j, 0, n) {
				if (!visited[i][j]) {
					cnt = bfs(i,j,n);
					if (cnt != n) {
						flag = false;
						break;
					}
				}
			}
		}
		if (flag)
			Ps("good\n");
		else
			Ps("wrong\n");
	}
	return 0;
}
