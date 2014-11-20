/*
 *  Author		: Krypten
 *  Algorithm	: Biconnected Graph
 *					- connected graph
 * 					- No Articulation Points
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
#define SIZE 17

typedef struct {
	int num;
	int low;
	int noChildren;
	V(int) adjList;
} node;
node graph[SIZE];

int EdgeList[SIZE][3];
bool isArticulationPt[SIZE];
bool visited[SIZE];

int timeCtr = 0;

void checkArticulationPt(int u)
{
	graph[u].low = graph[u].num;
	visited[u] = true;

	F(i, 0, (int)graph[u].adjList.size()) {
		int v = graph[u].adjList[i];
		if (graph[v].num == -1) {
			graph[v].num = graph[u].num + 1;
			graph[u].noChildren++;
			checkArticulationPt(v);
			graph[u].low = min(graph[u].low, graph[v].low);

			if (graph[v].low > graph[u].num)
				isArticulationPt[u] = true;
		} else if (graph[v].num < graph[u].num-1) {
			graph[u].low = min(graph[u].low, graph[v].num);
		}
	}
}

ill biConnected(int level, int n, int m)
{
	int cnt = 0;
	F(i,0,SIZE)
		graph[i].adjList.clear(), graph[i].noChildren = 0, graph[i].low = graph[i].num = -1;

	M(isArticulationPt, 0);
	M(visited, 0);

	ill cost = 0LL;
    F(i, 0, m) {
	    //cout << level << "\n";
		if (level & 1<<i) {
			cost += (ill) EdgeList[i][2];
			graph[EdgeList[i][0]].adjList.pb(EdgeList[i][1]);
			graph[EdgeList[i][1]].adjList.pb(EdgeList[i][0]);
			cnt++;
		}
	}
	//cout << "Count : " << cnt << endl;
	if (cnt >= n-1) {
		graph[0].num = 0;
		checkArticulationPt(0);
		F(i,0,n)
			if (!visited[i])
				return -1LL;
		F(i,0,n)
			if (isArticulationPt[i])
				return -1LL;
		return cost;
	}
	return -1LL;
}

ill solve(int n, int m)
{
	ill cost = 1000000000000LL, temp;
	bool flag = false;
	F(i,0,(1<<m)) {
		temp = biConnected(i,n,m);
		if (temp != -1LL)
			cost = min(cost, temp), flag = true;
	}
	if (flag)
		return cost;
	return -1LL;
}

int main()
{
	input();
	int t = 0;
	int n, m;
	int u, v, w;

    //S(t);
	//t = 1;
	while (++t) {
		S(n), S(m);
		if (n == 0 && m == 0)
            break;
		F(i, 0, m) {
			S(u), S(v), S(w);
			EdgeList[i][0] = u-1;
			EdgeList[i][1] = v-1;
			EdgeList[i][2] = w;
		}

		ill result = solve(n, m);
        if (result == -1LL)
        	printf("There is no reliable net possible for test case %d.\n", t);
        else
        	printf("The minimal cost for test case %d is %d.\n", t, result);
	}
	return 0;
}
