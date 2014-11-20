/*
*  Author		: Krypten
*  Algorithm	: Strongly connected components (TARJAN)
*/

#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
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
#define SIZE 1024

char str[SIZE][SIZE];
int visited[SIZE][SIZE];

int n, m;
int compCnt;

int moves[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
char state[] = {'W', 'E', 'N', 'S'};

inline bool legalMove(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
        return true;
    return false;
}

void bfs(int x, int y)
{
	int X, Y;
	queue<pii> q;
	q.push(pii(x,y));
	while (!q.empty()) {
		pii v = q.front(); q.pop();
		X = v.fr;
		Y = v.se;
		if (visited[X][Y])
            continue;
        //visited[X][Y] = true;
        visited[X][Y] = compCnt;
		switch(str[X][Y]) {
			case 'S': X++;
			break;
			case 'N': X--;
			break;
			case 'E': Y++;
			break;
			case 'W': Y--;
			break;
		}
		if (legalMove(X,Y))
			q.push(pii(X,Y));

		F(i,0,4) {
			X = v.fr + moves[i][0];
			Y = v.se + moves[i][1];
			if (legalMove(X, Y) &&  str[X][Y] == state[i])
				q.push(pii(X,Y));
		}
	}
}

int main()
{
	input();
	int t;

//S(t);
	t = 1;
	while (t--) {
		S(n), S(m);
		F(i, 0, n)
		Ss(str[i]);

		compCnt = 0;
		M(visited, false);
		F(i,0,n)
			F(j,0,m)
				if (!visited[i][j]) {
					compCnt++;
					bfs(i,j);
				}

		/*F(i,0,n) {
			F(j,0,m)
			P(visited[i][j]),Ps(" ");
			Ps("\n");
		}*/
		P(compCnt),Ps("\n");

	}
	return 0;
}
