/*
 *  Author		: Krypten
 *  Algorithm	: Topological Sort
 */

#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

typedef pair <int, int> pii;
typedef vector <pii> vii;

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
#define fr first
#define se second

vector <vii> AdjList;
vector <int> indeg;
vector <int> topo;

struct comparator {
	bool operator()(const int a, const int b) {
		return a > b;
	}
};

void toposort(int n) {
	int u, v;
	priority_queue<int,vector<int>,comparator> nextNode;

	F(i,1,n+1)
		if(!indeg[i])
			nextNode.push(i);

	while(!nextNode.empty()) {
		u = nextNode.top();nextNode.pop();
		topo.push_back(u);
		F(i,0,(int)AdjList[u].size()) {
			pii v = AdjList[u][i];
			indeg[v.fr]--;
			if(!indeg[v.fr])
				nextNode.push(v.fr);
		}
	}
}

int main()
{
	int t;
	int i, k;
	int n, m;
	int u, v;
	//int source;

	//S(t);
	t = 1;
	while (t--) {
		S(n),S(m);
		topo.clear();
		indeg.assign(n+1, 0);
	  	AdjList.assign(n+1, vii());
		
		F(i,0,m) {
			S(u),S(k);
			F(j,0,k) {
				S(v);
				AdjList[u].push_back(pii(v, 1));
				AdjList[v].push_back(pii(u, 1));
			}
			indeg[u] += k;
	  	}
	  	toposort(n);
		P(topo[0]);
		F(i,1,n)
			printf(" %d", topo[i]);
		Ps("\n");
	}
	return 0;
}