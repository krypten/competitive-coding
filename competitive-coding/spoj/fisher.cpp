/*
 *  Author		: Krypten
 *  Algorithm	: DP
 */

#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

#define INF 100000
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
#define debug(i,sz,x) F(i,0,sz){cout<<x[i].start<<" ";}cout<<endl
#define MAX(a,b) 	((a)>-(b)?(a):(b))
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

#define TIME 2000
#define SIZE 60

int timeArr[SIZE][SIZE];
int toll[SIZE][SIZE];
pii dp[SIZE][TIME];

int limit_time;

pii solve(int i, int limit, int n)
{
    //cout << i << " " << limit << "\n";
	pii& ans = dp[i][limit];
	if (i == n-1)
		return pii(0, limit);
	if (limit < 0)
		return pii(INF,0);
	if (ans.fr != -1)
		return ans;
	ans.fr = INF;
	F(j, 0 , n)
		if (i != j && limit >= timeArr[i][j]) {
            pii temp = solve(j, limit - timeArr[i][j], n);
            if (temp.fr + toll[i][j] < ans.fr) {
                    ans.fr = temp.fr + toll[i][j];
                    ans.se = temp.se;
            }
		}
        //ans = min(ans, solve(j, limit - timeArr[i][j], n) + toll[i][j]);

	return ans;
}

int main()
{
	input();
	int t;
	int n;
	int st, sur, pr;
	//S(t);
	t = 1;
	while (t) {
		S(n), S(limit_time);
		if (n == 0 && limit_time == 0)
			break;
		F(i, 0 , n)
			F(j, 0 , n)
				S(timeArr[i][j]);

		F(i, 0 , n)
			F(j, 0 , n)
				S(toll[i][j]);

		M(dp,-1);
		pii ans = solve(0, limit_time,n);
		printf("%d %d\n", ans.fr, limit_time - ans.se);
	}
	return 0;
}
