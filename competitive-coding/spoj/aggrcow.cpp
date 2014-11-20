/*
 *  Author		: Krypten
 *  Algorithm	: Binary Search
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
#define  first
#define se second

void input() {
#if !ONLINE_JUDGE
    eopen("input.txt","r",stdin);
#endif
}

int arr[100040];

bool find(int v,int n,int m){
	int pre=arr[0],c=0;
	F(i,1,n)
		if(arr[i]-pre>=v){
			c++;
			pre=arr[i];
		}
	
	if(c>=m) return true;
	return false;
}

int main()
{
	input();
	int t;
	int n, m;

	S(t);
	//t = 1;
	while (t--) {
		S(n), S(m);
		F(i, 0, n)
			S(arr[i]);
		sort(arr, arr + n);
		//F(i,0,n)
		//	printf("%d ", arr[i].);
		--m;
		int left=0,right=arr[n-1],mid;
		while(left<=right){
			mid=(left+right)/2;
			if(find(mid,n,m)) left=mid+1;
			else right=mid-1;
		}
		printf("%d\n",left-1);
	}
	return 0;
}
