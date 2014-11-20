/*
 *  Author      : Krypten
 *  Algorithm   : Longest Path in DAG
 */

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

#define MAX_V 100500

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<pii> > vvi;


vvi adjList;
bool visited[MAX_V];

pii maxHeightDiameter(int node)
{
    
    pii ans = pii(0,0);
    int maxSecondHeight = 0;
    int f_i = -1;
    int s_i = -1;
    
    if (visited[node])
        return ans;
    visited[node] = true;

    for (int i = 0; i < adjList[node].size(); i++) {
        if (!visited[adjList[node][i].first]) {
            pii temp = maxHeightDiameter(adjList[node][i].first);
            if (temp.first + adjList[node][i].second  > ans.first) {
                maxSecondHeight = ans.first;
                s_i = i;
                ans.first = temp.first + adjList[node][i].second;
                f_i = i;
            } else if (temp.first + adjList[node][i].second > maxSecondHeight) {
                maxSecondHeight = temp.first + adjList[node][i].second;
                s_i = i;
            }
            ans.second = max(temp.second, ans.second);
        }
    }

    ans.second = max(ans.second, ans.first + maxSecondHeight);

    return ans;
}

int main()
{
    int t, n;
    int u, v, w;
    //scanf("%d", &t);
    t = 1;
    while (t--) {
        cin >> n;
        adjList.clear();
        adjList.resize(n + 1);
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i < n; i++) {
            //scanf("%d %d %d", &u, &v, &w);
            scanf("%d %d", &u, &v); w = 1;

            adjList[u].push_back(pii(v, w));
            adjList[v].push_back(pii(u, w));
        }
        pii ans = maxHeightDiameter(1);
        cout << max(ans.first, ans.second)<< endl;
    }
    return 0;
}
