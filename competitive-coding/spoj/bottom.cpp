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
V(V(pii) ) AdjList;
V(int) d_num;
V(int) d_low;
V(bool) blackList;
V(bool) visited;
stack <int> stk;

int timeCtr;

void tarjanSCC(int u)
{
	d_low[u] = d_num[u] = timeCtr++;
	stk.push(u);
	visited[u] = true;

	//printf("\tOK");

	F(j,0, (int) AdjList[u].size()) {
		pii v = AdjList[u][j];
		if (d_num[v.fr] == -1) {
			tarjanSCC(v.fr);
			d_low[u] = min(d_low[u], d_low[v.fr]);
        } else if (visited[v.fr])
			d_low[u] = min(d_low[u], d_num[v.fr]);
	}

	if(d_low[u] == d_num[u]) {
		//printf("SCC %d: " , ctr2);
		while(!stk.empty()) {
			int vt = stk.top(); stk.pop();
			//P(vt), Ps(" ");
			visited[vt] = false;
			d_low[vt] = d_num[u];
			if (u == vt) break;
		}
		//Ps("\n");
	}
}

void tarjan(int n)
{
		d_num.assign(n+1, -1);
		d_low.assign(n+1, -1);
		visited.assign(n+1, 0);

		timeCtr = 0;
		while(!stk.empty()) stk.pop();

        //Ps("OK\n");
		F(i,1,n+1)
	        if (d_num[i] == -1)
	            tarjanSCC(i);
}

int main()
{
	input();
	int t;
	int n, m;
	int u, v;

	//S(t);
	t = 1;
	while (t) {

		S(n);
		if (n == 0)
			break;
        S(m);

		AdjList.assign(n+1, vector<pii>() );

		F(i, 0, m) {
			S(u), S(v);
			AdjList[u].pb(pii(v, 1));
			//AdjList[v].push_back(ii (u, 1));
		}

        tarjan(n);
		blackList.assign(n+1, 0);

        F(i ,1, n+1) {
            F(j,0, (int) AdjList[i].size()) {
                if (d_low[i] != d_low[AdjList[i][j].fr]) {
                    blackList[d_low[i]] = true;
                    break;
                }
            }
        }

        F(i,1,n+1)
            if (!blackList[d_low[i]])
                P(i), Ps(" ");

        Ps("\n");
	}
	return 0;
}
