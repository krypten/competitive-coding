/*
 *  Author		: Krypten
 *  Algorithm	: DFS
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
#define SIZE 8

int moves[SIZE][2] = {{2, 1}, {1, 2}, {2, -1}, {1, -2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
bool visited[16][16];
V(pii) board;

bool legalMove(int x, int y, int n)
{
	if (x >= 0 && x < n && board[x].fr <= y && board[x].se > y && visited[x][y])
		return true;
	return false;
}

void dfs(int x, int y, int n, int cnt, int &ans)
{
	//cout << x << " " << y  << " " << visited[x][y]<< "\n";
	ans = max(ans, cnt);
	F(i,0,SIZE) {	
		int X = x + moves[i][0];
		int Y = y + moves[i][1];
		//cout <<"\t" << X << " " << Y  << " " << visited[X][Y]<< "\n";

		if (legalMove(X,Y,n)) {
		//cout << "MOVE : " <<  X << " " << Y << "\n";
	
			visited[X][Y] = false;
			dfs(X, Y, n, cnt + 1, ans);
			visited[X][Y] = true;
		}
	}
}

int main()
{
	input();
	int t;
	int n;
	int u, v;
	//S(t);
	t = 0;
	while (++t) {
		S(n);
		board.assign(n, pii());
		if (n == 0)
			break;
		int sum = 0;
		F(i,0,n) {
			S(u),S(v);
			board[i] = (pii(u,u+v));
			sum += v;
		}

		M(visited, true);
		int ans = 0;
		visited[0][board[0].fr] = false;
		dfs(0,board[0].fr, n, 1, ans);
		//cout <<" HI " <<  sum-1 << " " << ans << endl;
		
		Ps("Case "), P(t), Ps(", "),P(sum-ans),Ps((sum-ans == 1 ? " square " : " squares ")), Ps("can not be reached.\n");
	}
	return 0;
}