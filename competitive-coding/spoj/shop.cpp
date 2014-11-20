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
#define SIZE 32
int n, m;

bool legalMove(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m) {
		return true;
	}
	return false;
}

int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool visited[SIZE][SIZE];
char matrix[SIZE][SIZE];

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
int ucs(node s, node d)
{
	M(visited, false);
	priority_queue<node, vector<node>, comparator> pq;
	node v;
	s.depth = 0;
	pq.push(s);
	while (!pq.empty()) {
		node u = pq.top(); pq.pop();
		//cout << u.x << " " << u.y << " " << u.depth << "\n";
		if (u.x == d.x && u.y == d.y) {
			return u.depth;
		}
		if (matrix[u.x][u.y] == 'X')
			continue;
		if (visited[u.x][u.y])
			continue;
		visited[u.x][u.y] = true;

		//cout << u.x << " " << u.y << " " << u.depth << "\n";
		F(i,0,4) {
			int X = u.x + moves[i][0];
			int Y = u.y + moves[i][1];
			if (legalMove(X, Y) && !visited[X][Y] && matrix[X][Y] != 'X') {
				node v; v.x = X; v.y = Y;
				v.depth = u.depth;
				if (matrix[X][Y] != 'D')
					v.depth = v.depth + (matrix[X][Y] - '0');
				//cout << "Pushing : " << v.x << " " << v.y << " " << v.depth << " " <<  u.depth << matrix[X][Y] << "\n";
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
	//S(t);
	t = 1;
	while (t) {
		S(m),S(n);
		if (m == 0 && n == 0) 
			break;
		F(i,0,n)
			F(j,0,m)
				scanf(" %c", &matrix[i][j]);

		node s, d;
		F(i,0,n)
			F(j,0,m) {
				if (matrix[i][j] == 'S') {
					s.x = i; s.y = j;
				} else if (matrix[i][j] == 'D') {
					d.x = i; d.y = j;
				}
			}

		P(ucs(s,d)), Ps("\n");
	}
	return 0;
}
