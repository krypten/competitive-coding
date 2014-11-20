/*
 *  Author      : Krypten
 *  Algorithm   : Subset Sum
 */

#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

#define INF INT_MAX/2
#define ONLINE_JUDGE 1

#define ull         unsigned long long
#define ill         long long int
#define pii         pair<int,int>
#define pb(x)       push_back(x)
#define mp make_pair
#define F(i,a,n)    for(int i=(a);i<(n);++i)
#define FI(i,a,n)   for(i=(a);i<(n);++i)
#define FD(i,a,n)   for(int i=(a);i>=(n);--i)
#define FE(it,x)    for(it=x.begin();it!=x.end();++it)
#define V(x)        vector<x>
#define S(x)        scanf("%d",&x)
#define Sl(x)       scanf("%lld",&x)
#define Ss(x)       scanf("%s", x)
#define P(x)        printf("%d",x)
#define Pl(x)       printf("%lld",x)
#define Ps(x)       printf("%s", x)
#define M(x,i)      memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b)    ((a)>(b)?(a):(b))
#define MIN(a,b)    ((a)>(b)?(b):(a))
#define LSOne(S)    (S & (-S))

ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

void input() {
#if !ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}

int a[100010];
bool dp[10010];

void solve(int n)
{
    M(dp,false);
    dp[0] = true;
    F(i,0,n) {
        //basically what he is doing is generating all possible
        //subsets and storing their sums.if he encounters the sum again
        //then he prints YES and if he encounters no collision then
        //he prints NO.
        //Essentially we could start j from the cummulative sum of the array to save
        //time. Now J represent sum, so for a given sum J , if j - a[i] is present and we have
        //already encountered j before the we say yes else we add this j sum set to our value
        //to our list(turn its value true).
        for(int j=10000;j>=a[i];--j)
        {
            if(dp[j-a[i]])
            {
                if(dp[j]){puts("YES");return ;}
                else dp[j]=true;
            }
        }
    }
    puts("NO");
}

int main()
{
    int t, n;
    S(t);
    while (t--) {
        S(n);
        F(i,0,n)
            S(a[i]);

        if (n > 100) {
            puts("YES");
            continue;
        }
        solve(n);
    }
    return 0;
}