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

ill factorial(int n)
{
    ill ans = 1;
    F(i,1,n+1)
        ans *= i;
    return ans;
}

int main()
{
	input();
	int t;
	int n, m;
    int u, v;
	string s;
	S(t);
	//t = 1;
	while (t--) {
        ill ans = 0;
		cin >> s;
        F(i,0,s.size()) {
            int cnt = 0;
            F(j,i+1, s.size()) {
                if (s[i] < s[j])
                    cnt++;
            }
            ans += (cnt*factorial(s.size()-i-1));
        }
        ans++;
        //cout << ans << endl;
        string result = "";
        while(ans > 0) {
            int x = ans%26;
            ans = ans / 26;
            result = char(x + 'A' -1) + result;
        }
        cout << result << endl;
	}
	return 0;
}
