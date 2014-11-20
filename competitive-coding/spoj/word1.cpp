/*
 *  Author      : Krypten
 *  Algorithm   : Euler Path/ Euler tour
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

ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

void input() {
#if !ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}


// LOGIC
int indeg[26];
int outdeg[26];
int color[26];
bool visited[26], graph[26][26];
char word[1024];


bool isConnected() {
    queue<int> q;
    F(i,0,26)
        color[i] = visited[i] ? 0 : 2;
    int i;
    for(i = 0; color[i]; ++i);
    color[i] = 1;
    q.push(i);
    while (!q.empty()) {
        i = q.front(); q.pop();
        F(j,0,26) {
            if ((graph[i][j] || graph[j][i]) && !color[j])
                q.push(j), color[j] = 1;
        }
        color[i] = 2;
    }
    F(i, 0, 26)
        if (color[i] != 2)
            return false;
    return true;
}

bool hasEulerPath() {
    if (!isConnected())
        return false;
    int end = 0;
    int start = 0;
    F(i, 0, 26) {
        if (outdeg[i] - indeg[i] == 1)
            end++;
        else if(indeg[i] - outdeg[i] == 1)
            start++;
        else if (indeg[i] != outdeg[i])
            return false;
    }

    if (start + end == 0 || (end == 1 && start == 1))
        return true;
    return false;
}

int main()
{
    input();
    int t;
    int u, v;
    int n, len;
    S(t);
    //t = 1;
    while(t--) {
        M(indeg, 0);
        M(outdeg, 0);
        M(graph, 0);
        M(visited, 0);

        S(n);
        F(i,0, n) {
            Ss(word);
            len = strlen(word);
            indeg[u=word[0] -'a']++;
            outdeg[v=word[len-1]-'a']++;
            graph[u][v] = visited[u] = visited[v] = 1;
        }
        if (hasEulerPath())
            Ps("Ordering is possible.\n");
        else
            Ps("The door cannot be opened.\n");
    }
    return 0;
}
