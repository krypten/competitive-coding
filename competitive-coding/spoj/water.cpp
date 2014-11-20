/*
 *  Author		: Krypten
 *  Algorithm	: BFS + Priority Queue
 */

#include <bits/stdc++.h>
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

int moves[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int matrix[128][128];
bool visited[128][128];
int n, m;
bool legalMove(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}

int main()
{
	input();
	int t;
	S(t);
	//t = 1;
	while (t--) {
		S(n), S(m);
		F(i,0,n) F(j,0,m) S(matrix[i][j]);

		priority_queue<pii, V(pii), greater<pii> > pq;
		M(visited, false);
		F(i,0,n) {
			visited[i][0] = visited[i][m-1] = 1;
			pq.push(pii(matrix[i][0], i*m));
			pq.push(pii(matrix[i][m-1], i*m +m-1));
		}

		F(j,1, m-1) {
			visited[0][j] = visited[n-1][j] = 1;
			pq.push(pii(matrix[0][j], j));
			pq.push(pii(matrix[n-1][j], (n-1)*m + j));
		}

		int ans = 0;
		while (!pq.empty()) {
			pii u = pq.top(); pq.pop();

			int b = u.fr, i =u.se/m, j = u.se%m;
			pii adjCell[4];
			int tot = 0;

			F(k,0,4) {
				int X = i + moves[k][0];
				int Y = j + moves[k][1];
				if(legalMove(X,Y) && !visited[X][Y]) {
					visited[X][Y]=1;

					if(matrix[X][Y] <= b) {
						ans += (b - matrix[X][Y]);
						adjCell[tot++] = pii(b, X*m + Y);
					} else
						adjCell[tot++] = pii(matrix[X][Y], X*m + Y);
				}
			}

			F(k,0,tot)
				pq.push(adjCell[k]);
		}
		P(ans),Ps("\n");
	}
	return 0;
}