/*
 *  Author		: Krypten
 *  Algorithm	: Greedy
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

typedef pair<int, pii> pip;

void input() {
#if !ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}

int r,g,b;
int red[128];
int blue[128];
int green[128];

pii reduceUpdate(int i)
{
	int sum = 0;
	int odd = 0;
	switch(i) {
		case 0:
			F(i,0,r) {
				red[i] = red[i]/2;
				if (sum < red[i])
					sum = red[i];
				if (red[i]&0x1)
					odd++;
			}
			break;
		case 1:
			F(i,0,g) {
				green[i] = green[i]/2;
				if (sum < green[i])
					sum = green[i];
				if (green[i]&0x1)
					odd++;
			}
		
			break;
		case 2:
			F(i,0,b) {
				blue[i] = blue[i]/2;
				if (sum < blue[i])
					sum = blue[i];
				if (blue[i]&0x1)
					odd++;
			}
			break;
	}
	return pii(sum,odd);
}

int main()
{
	input();
	int t;
	int m;
	S(t);
	//t = 1;
	while (t--) {
		S(r),S(g),S(b),S(m);
		int sum_r = 0;
		int sum_g = 0;
		int sum_b = 0;
		int odd_r = 0;
		int odd_g = 0;
		int odd_b = 0;

		F(i,0,r) {
			S(red[i]);
			if (sum_r < red[i])
				sum_r = red[i];
			if (red[i]&0x1)
				odd_r++;
		}
		F(i,0,g) {
			S(green[i]);
			if (sum_g < green[i])
				sum_g = green[i];
			if (green[i]&0x1)
				odd_g++;
		}
		F(i,0,b) {
			S(blue[i]);
			if (sum_b < blue[i])
				sum_b = blue[i];
			if (blue[i]&0x1)
				odd_b++;
		}

		pip arr[] = {pip(sum_r,pii(odd_r,0)), pip(sum_g,pii(odd_g,1)), pip(sum_b,pii(odd_b,2))};
			
		F(i,0,m) {
			int index = 0;
			sort(arr, arr + 3); 
			pii ret = reduceUpdate(arr[2].se.se);
			arr[2] = pip(ret.fr, pii(ret.se, arr[2].se.se));
		}

		int ans = 0;
		//debug(i,r,red);
		//debug(i,g,green);
		//debug(i,b,blue);
		F(i,0,r)
			if (ans < red[i])
				ans = red[i];
		F(i,0,g)
			if (ans < green[i])
				ans = green[i];
		F(i,0,b)
			if (ans < blue[i])
				ans = blue[i];
		P(ans),Ps("\n");
	}
	return 0;
}
