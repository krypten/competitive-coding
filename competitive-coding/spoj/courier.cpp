/*
	STATE
    	fn(mask, prev) = min( fn(set kth bit in mask, k) + dist[dest[prev]][src[k]] + dist[src[k]][dest[k]] ) for every k not in mask

Here mask denotes the set of deliveries that have been completed and prev is the index(from src[]/dest[] arrays) of the last delivery that has been completed. dist[x][y] represents the shortest distance between the nodes x & y. This can be found using Floyd Warshal algorithm.

The answer is found by iterating over all possible starting masks plus the distance from the starting city -
    min(fn(1<<i,i) + dist[b][src[i]] + dist[src[i]][dest[i]] for all values of i)

*/

/*
 *  Author		: Krypten
 *  Algorithm	: TSP + Floyd Warshal
 */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

#define INF 1000000000
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

//  Logic Starts here
#define COURIER 12
#define MX_NODE 124

int home;
int pktCnt;
int dist[MX_NODE][MX_NODE];
int src[COURIER];
int dest[COURIER];

int dp[1<<COURIER][MX_NODE];

void floyd(int n)
{
	F(k,0,n) F(i, 0, n) F(j, 0, n)
		if (dist[i][k] + dist[k][j] < dist[i][j])
			dist[i][j] = dist[i][k] + dist[k][j];
}

int solve(int mask, int prev) {
	//cout << " MASK " << mask  << " " << ((1<<pktCnt)-1) << " " << pktCnt <<endl;
	int& ans = dp[mask][prev];
	if (ans != -1)
		return dp[mask][prev];
    if (mask == ((1<<pktCnt)-1)) {
        return (ans = dist[prev][home]);
    }
	ans = INF;
	F(k, 0, pktCnt) {
		if (!((1<<k)&mask)) {
			//cout << "MASK : " << mask << " ANSWER : " << solve(mask|1<<k, dest[k]) + dist[prev][src[k]] + dist[src[k]][dest[k]] << endl;
			ans = min(ans, solve(mask|1<<k, dest[k]) + dist[prev][src[k]] + dist[src[k]][dest[k]] );
		}
	}
	return ans;
}

int main() {
	input();
	int t;
	int ans;
	int n, m;
	int u, v, w;

	//t = 1;
	S(t);
	while (t--) {
		S(n), S(m), S(home); home--;
		F(i,0,n)
			F(j,0,n)
				dist[i][j] = (i==j)?0:INF;
		F(i, 0, m) {
			S(u), S(v), S(w);
			dist[u-1][v-1] = w;
			dist[v-1][u-1] = w;
		}

        /*
		F(i,0,n) {
			F(j,0,n)
			P(dist[i][j]), Ps(" ");
			Ps("\n");
		}
		*/
		M(src,  0);
		M(dest, 0);
		M(dp, -1);

		S(m);
		pktCnt = 0;
		F(i, 0, m) {
			S(u), S(v), S(w);
			F(j,0,w) {
				src[pktCnt] = u-1; dest[pktCnt] = v-1; pktCnt++;
			}
		}
		floyd(n);
        //cout << "Solving TSP \n";
		P(solve(0, home)), Ps("\n");
	}
	return 0;
}
