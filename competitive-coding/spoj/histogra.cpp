/*
 *  Author		: Krypten
 *  Algorithm	: Stack (Largest Rectangle in Histogram)
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

ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

void input() {
#if !ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}

#define pli pair<ill,int>

ill hist[100024];
stack<pli> storage;
ill getLargestRectArea(int n)
{
	int index;
	ill currArea;
	ill maxArea = 0;
	stack<pli> storage;
	F(i, 0, n+1) {
		while (!storage.empty() && (i == n || hist[i] < storage.top().fr)) {
			pli curr = storage.top(); storage.pop();
			ill currArea = (storage.empty()?i:i-storage.top().se-1) * curr.fr;
			maxArea = MAX(maxArea, currArea);
		}
		if (i < n) {
			storage.push(pli(hist[i],i));
		}
	}
	return maxArea;
}

int main()
{
	input();
	int t, n;
	//S(t);
	t = 1;
	while (t) {
		S(n);
		if (n == 0)
			break;
		F(i,0,n)
			Sl(hist[i]);

		Pl(getLargestRectArea(n)),Ps("\n");
	}
	return 0;
}
