/*
 *  Author		: Krypten
 *  Algorithm	: Adhoc
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
#define debug(i,sz,x) F(i,0,sz){cout<<x[i].start<<" ";}cout<<endl
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

typedef struct {
	int i;
	int start;
	int dur;
	int price;
} Node;

Node arr[1000020];
int dp[1000020];

bool comparator(const Node a, const int b) {
	return a.start < b;
}

bool comp2 (const Node& a ,const Node& b)
{
	if (a.start == b.start && a.dur < b.dur) {
		return true;
	} else if (a.start < b.start) {
		return true;
	}
	return false;
}

int solve(int index, int n)
{
	int& ans = dp[index];
	if (index >= n)
		return 0;
	if (ans != -1)
		return dp[index];
	
	Node *x = lower_bound(&arr[0], &arr[n], arr[index].start + arr[index].dur, comparator);
	//cout << arr[index].start << " " << arr[index].dur << " @ " << index << " " <<  x->start << " " << x->dur <<  " @ " << x->i << endl;
	//int temp; cin >> temp;cout << temp << endl;	
	ans = 0;
	ans = max(ans, solve(index+1,n));
	if (x->i != n)
		ans = max(ans, solve(x->i,n) + arr[index].price);
	else 
		ans = max(ans, arr[index].price);
	
	return ans; 
}

int main()
{
	input();
	int t;
	int n, m;
	int st, sur, pr;
	S(t);
	//t = 1;
	while (t--) {
		S(n);
		F(i, 0 , n) 
			S(arr[i].start),S(arr[i].dur),S(arr[i].price);
		sort(arr, arr + n, comp2);

		F(i,0,n)
			arr[i].i = i;
		arr[n].i = n;
		
		M(dp,-1);	
		int ans = solve(0, n);
		P(ans),Ps("\n");
	}
	return 0;
}
