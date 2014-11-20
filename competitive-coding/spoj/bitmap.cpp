/*
 *  Author	: Krypten
 *  Algorithm	: BFS
 */

#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

const int INF = 100000;
const int MAX = 256;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

bool validMove(int x, int y, int sizex, int sizey)
{
	if (x >= 0 && y >= 0 && x < sizex && y < sizey) {
		return true;
	}
	return false;
}

int main()
{
	int t;
	int n, m;
	char c;
	bool arr[MAX][MAX];
	int dist[MAX][MAX];

	
	cin >> t;
	while (t--) {
		cin >> n >> m;
		queue<pip> levelqueue;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dist[i][j] = INF;
			}
		}		

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf(" %c", &c);
				if (c == '0')
					arr[i][j] = false;
				else {
					arr[i][j] = true;
					levelqueue.push(pip(i,pii(j, 0)));
				}
			}
		}

		while (!levelqueue.empty()) {
			pip current = levelqueue.front(); levelqueue.pop();
			if (current.second.second < dist[current.first][current.second.first]) {
				dist[current.first][current.second.first] = current.second.second;
			} else {
				continue;
			}

			int moves[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
			for (int i = 0; i < 4; i++) {
				int x = current.first + moves[i][0];
				int y = current.second.first + moves[i][1];
				if (validMove(x,y,n,m)) {
					levelqueue.push(pip(x,pii(y, current.second.second + 1)));
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", dist[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

