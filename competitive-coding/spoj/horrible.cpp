/*
 *  Author		: Krypten
 *  Algorithm	: Binary Indexed Tree
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

/*
 * Type : BIT (RMQ)
 */

#define SIZE 100002
class FenwickTree {
	private:
		int size;
		ill ft[SIZE];

	public:
	FenwickTree() {size = 0;}
	// initialization: n + 1 zeroes, ignore index 0
	FenwickTree(int n) {
		M(ft,0);//ft.assign(n + 1, 0);
		size = n;
	}

	ill rsq(int b) {                                     // returns RSQ(1, b)
		ill sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	}

	ill rsq(int a, int b) {                              // returns RSQ(a, b) // Read
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

	// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec) // Update
	void adjust(int k, ill v) {                    // note: n = ft.size() - 1
		for (; k < (int)SIZE-1; k += LSOne(k)) ft[k] += v; }
};


int main()
{
	input();
	int t, n,c;
	S(t);
	//t = 1;
	while (t--) {
		ill x,p, q, v;
		S(n),S(c);

		FenwickTree bit1(n);
		FenwickTree bit2(n);

		F(i,0,c) {
			Sl(x),Sl(p),Sl(q);
			if (x == 0) {
				Sl(v);
				bit1.adjust(p,v); bit1.adjust(q+1,-v);
				bit2.adjust(p,-(ill)v * (p - 1)); bit2.adjust(q + 1,(ill)v * q);
			}
			else  {
				ill ans = bit1.rsq(q) * q + bit2.rsq(q) - bit1.rsq(p-1)*(p-1) - bit2.rsq(p-1) ;
				Pl(ans),Ps("\n");
			}
		}
	}
	return 0;
}