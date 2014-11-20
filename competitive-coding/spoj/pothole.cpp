/*
    Algorithm : Edmond Karp [Ford Fulkerson BFS]
*/

#include <iostream>
#include <cstdio>
#include <limits.h>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

// Number of vertices in given graph
#define V 256

/*
    function bfs()
        return      - true if path possible else false
        description - Fills parent[] to store the path
*/
bool bfs(int rGraph[V][V], int s, int t, int parent[], int n)
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front(); q.pop();

        for (int v = 0; v < n; v++) {
            if (visited[v]==false && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[t] == true);
}

// Returns tne maximum flow from s to t in the given graph
int fordFulkerson(int graph[V][V], int s, int t, int n)
{
    int u, v;

    // residual graph creaated from original graph
    int rGraph[V][V];
    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
             rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0;

    // Augment the flow while s ->-> t exists
    while (bfs(rGraph, s, t, parent, n))
    {
        // minimum residual capacity
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        //update residual capacities
        for (v=t; v != s; v=parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
int testCases;
      int n, m;
      int i, j;
    int v, w;
    int s, t;

    scanf("%d", &testCases);

    int graph[V][V];
	while (testCases--) {
		memset(graph, 0, sizeof(graph));

        scanf("%d", &n);
        if (n == 1) {
             printf ("1\n");
             continue;
        }
        if (n < 1) {
            printf("0\n");
            continue;
        }
        s = 0;
        t = n-1;
        w = n;
		for (i = 0; i < n - 1; i++) {
            scanf("%d", &m);
            if (i == 0) {
                w = m;
            }
            for (j = 0; j < m; j++) {
                scanf("%d", &v);
                if (i == 0 || v == n)
                    graph[i][v-1] = 1;
                else
                    graph[i][v-1] = w;
            }
		}
        /* DEBUG matrix print
		for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n; j++) {
                printf("%d ", AdjMat[i][j]);
            }
            printf("\n");
		}
		*/

        cout << fordFulkerson(graph, s, t, n) << "\n";
	}
    return 0;
}
