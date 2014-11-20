/*
 *  Author      : Krypten
 *  Algorithm   : LCS, DP
 */

#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

#define INF INT_MAX/2
#define SIZE 5050

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

ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

void input() {
#if !ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif 
}

char s[5050];
static short dp[2][SIZE];
int main()
{
    int tc;
    //scanf("%d",&tc);
    tc = 1;
    while(tc--)
    {
        int len;
        S(len);
        Ss(s);
        F(j,0,len+1)
            dp[0][j] = 0;
        dp[1][0] = 0;

        bool f = true;
        F(i,1,len+1) {
            F(j,1,len+1)
                dp[f][j] = (s[i-1]==s[len-j])?dp[!f][j-1] + 1:max(dp[!f][j], dp[f][j-1]);
            f = !f;
        }


        printf("%d\n",len - dp[len%2][len]);
        /*
        F(i,0,len) {
            debug(j,len,dp[i]);
            cout << endl;
        }
        */
    }
    return 0;
}