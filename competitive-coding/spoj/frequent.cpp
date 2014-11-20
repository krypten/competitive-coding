/*
 *  Author		: Krypten
 *  Algorithm	: Segment Tree
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

//---------------------------------


const int SIZE = 1<<17;

struct Node {
	int mfreq;
	int lfreq;
	int rfreq;
};

int a[SIZE];
struct Node Tree[SIZE<<1];

void initialise(int node,int i, int j)
{
	if (i == j) {
		Tree[node].mfreq = Tree[node].lfreq = Tree[node].rfreq = 1; return; 
	}

	int m = (i + j) >> 1;
	initialise(node<<1, i, m);
	initialise((node<<1)+1, m+1, j);
	if (a[m] == a[m+1]) {
		Tree[node].lfreq = Tree[node<<1].lfreq + Tree[(node<<1) + 1].lfreq *(a[i] == a[m]);
		Tree[node].rfreq = Tree[(node<<1) + 1].rfreq + Tree[node<<1].rfreq * (a[j] == a[m+1]);
		int temp = Tree[node<<1].rfreq + Tree[(node<<1)+1].lfreq;
		Tree[node].mfreq = max(temp, max(Tree[node<<1].mfreq, Tree[(node<<1)+1].mfreq));
	} else {
		Tree[node].lfreq = Tree[node<<1].lfreq;
		Tree[node].rfreq = Tree[(node<<1)+1].rfreq;
		Tree[node].mfreq = max(Tree[node<<1].mfreq, Tree[(node<<1)+1].mfreq);
	}
}

int query(int node, int i, int j, int u, int v)
{
	if (u == i && j == v)
		return Tree[node].mfreq;
	int m = (i + j)>>1;
	if (v <=m)
		return query(node <<1, i,m,u,v);
	if (u > m)
		return query((node<<1) + 1,m+1,j,u,v);
	
	int left = query(node<<1,i,m,u,m);
	int right = query((node<<1) + 1,m+1,j,m+1,v);

	if (a[m] == a[m+1]) {
		int temp = min(Tree[node<<1].rfreq, m-u+1) + min(Tree[(node<<1)+1].lfreq, v-m);
		return max(temp, max(right, left));
	} else {
		return max(left, right);
	}
}


int main()
{
	input();
	int t, n, q;
	int u, v;
	//S(t);
	t = 1;
	while (t) {
		S(n);
		if (n == 0)
			break;
		S(q);
		F(i,0,n)
			S(a[i]);
		initialise(1, 0, n-1);
		F(i,0,q){
			S(u), S(v);
			if(u == v) 
				Ps("1\n");
			else 
				P(query(1, 0, n-1, --u, --v)),Ps("\n");
		}
	}
	return 0;
}