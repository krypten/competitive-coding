/*
 *  Author      : Krypten
 *  Algorithm   : DP Edit Distance
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

#define SIZE 3000
#define MOD 5
char str1[SIZE];
char str2[SIZE];
static int a[MOD][SIZE];

int main()
{
    int ax, b, k;
    int t,len1,len2,i,j,m,temp1,temp2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str1);
        scanf("%s",str2);
        len1=strlen(str1);
        len2=strlen(str2);
        for(i=0;i<MOD;i++)
            a[i][0]=i;
        for(i=1;i<=len2;i++)
            a[0][i]=i;
        for(i=1;i<=len1;i++) {
            for(j=1;j<=len2;j++) {
                if (i-1 == 0)
                    a[i-1][j] = j;
                if (j-1 == 0) {
                    if (i > 0)
                        a[(i-1)%MOD][j-1] = i-1;
                    a[i%MOD][j-1] = i;
                }
                m=(str1[i-1]==str2[j-1]) ? 0:1;
                temp1=min(a[(i-1)%MOD][j]+1,a[i%MOD][j-1]+1);
                temp2=a[(i-1)%MOD][j-1]+m;
                a[i%MOD][j]=min(temp1,temp2);
//                debug(k,len2,a[i%MOD]);
            }
            /*
            F(u,0,len2+1)
                P(a[(i-1)%MOD][u]),Ps(" ");
            Ps("\n");
            */
        }
        P(a[len1%MOD][len2]),Ps("\n");
    }
    return 0;
}