/**
 *  Algorithm : Bi Paritie Matching
 *
 */

#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

typedef struct {
	int x;
	int y;
} point;

#define N 512
#define M 256

point nodesList[N+M];
bool adjMatrix[N][M];

// A DFS based
bool bpm(bool bpGraph[N][M], int u, bool seen[], int matchR[], int n, int m)
{
    for (int v = 0; v < m; v++) {
        if (bpGraph[u][v] && !seen[v]) {
            seen[v] = true;

            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR, n, m)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int bipartie(bool bpGraph[N][M], int n, int m)
{
    int matchR[N];
    memset(matchR, -1, sizeof(matchR));

    int result = 0;
    for (int u = 0; u < n; u++) {
        bool seen[M];
        memset(seen, 0, sizeof(seen));

        if (bpm(bpGraph, u, seen, matchR, n, m))
            result++;
    }
    return result;
}

int main()
{
	int t;
	int i, j;
	int n, m;
	int speed;
	int lim, ans;
	point temp;

    scanf("%d", &t);
	while (t--) {
		memset(adjMatrix, 0, sizeof(adjMatrix));

		scanf("%d %d %d %d", &n, &m, &speed, &lim);
		for (i = 0; i < n + m; i++) {
			scanf("%d %d", &temp.x, &temp.y);
			nodesList[i] = temp;
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				int dis = abs(nodesList[i].x - nodesList[n+j].x) + abs(nodesList[i].y - nodesList[n+j].y);
				if (dis*200 <= speed*lim) {
					adjMatrix[i][j] = true;
				}
			}
		}
		ans = bipartie(adjMatrix, n, m);
		printf("%d\n", ans);
	}
	return 0;
}
