/*
 *  Author		: Krypten
 *  Algorithm	: Diameter
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

#define SIZE 1024

int n, m;
int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool visited[SIZE][SIZE];
char matrix[SIZE][SIZE];

typedef struct {
	int x;
	int y;
	int depth;
} node;

bool legalMove(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}

pii maxHeightDiameter(node u)
{
	
	pii ans = pii(0,0);
	int maxSecondHeight = 0;
	//int f_i = -1;
	//int s_i = -1;
	
	if (visited[u.x][u.y] || matrix[u.x][u.y] == '#')
		return ans;
	visited[u.x][u.y] = true;

	F(i,0,4) {
		int X = u.x + moves[i][0];
		int Y = u.y + moves[i][1];
		if (legalMove(X, Y) && !visited[X][Y] && matrix[X][Y] == '.') {
			node v; v.x = X; v.y = Y;
			pii temp = maxHeightDiameter(v);
			if (temp.first + 1 > ans.first) {
				maxSecondHeight = ans.first;
				//s_i = i;
				ans.first = temp.first + 1;
				//f_i = i;
			} else if (temp.first + 1 > maxSecondHeight) {
				maxSecondHeight = temp.first + 1;
				//s_i = i;
			}
			ans.second = max(temp.second, ans.second);
		}
	}

	ans.second = max(ans.second, ans.first + maxSecondHeight);

	return ans;
}

int main()
{
	input();
	int t;
	S(t);
	//t = 1;
	while (t--) {
		S(m),S(n);
		F(i,0,n)
			F(j,0,m)
				scanf(" %c", &matrix[i][j]);

		node s;
		F(i,0,n)
			F(j,0,m)
				if (matrix[i][j] == '.') {
					s.x = i; s.y = j;
					break;
				}
		M(visited, false);
		pii ans = maxHeightDiameter(s);

		Ps("Maximum rope length is "),P(max(ans.first, ans.second)), Ps(".\n");
	}
	return 0;
}