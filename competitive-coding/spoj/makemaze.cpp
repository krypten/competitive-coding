/*check boundary for exactly 2 points
then mark one as dest and other as src

the dfs for one path in it from src to dest;
*/

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

char str[32][32];
int visited[32][32] = {0};
int arr[64][64];
int n, m;
int maxi;
int ex;

void maze(int i , int j) {
	queue <pair <int, int> >q;

	q.push ( pair <int ,int> (i, j ));

	while( ! q.empty() ) {
		pair <int, int> V = q.front();

		i = V.first;
		j = V.second; 

		q.pop();
		
		if( visited[i][j] == 1) continue ;
		if(i == arr[1][0] && j == arr[1][1]) {
			ex = 1;
			return ;
		}

		visited[i][j] = 1;


		if( j > 0 && str[i][j-1] != '#' && visited[i][j-1] == 0) {
			q.push(pair <int, int> (i, j-1));
		} if( j < m-1 && str[i][j+1] != '#'&& visited[i][j+1] == 0) {
			q.push(pair <int, int> (i, j+1));
		} if( i > 0 && str[i-1][j] != '#' && visited[i-1][j] == 0) {
			q.push(pair <int, int> (i-1, j));
		} if( i < n-1 && str[i+1][j] != '#'&& visited[i+1][j] == 0) {
			q.push(pair <int, int> (i+1, j));
		}
	}
}

int main()
{
	int i, j;
	int t, ctr;
	int flag;

	scanf("%d", &t);
	
	while (t--) {
		flag = 1;
		ctr = 0;
		maxi = 1000000;

		scanf("%d %d", &n, &m);
		memset(str, 0, sizeof(str));
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));

		for ( i = 0; i < n; i++) {
			scanf("%s", &str[i]);
		}

		// check boundary condition;
		for (i = 0; i < m; i++) { 
			if (str[0][i] == '.') {
				arr[ctr][0] = 0; arr[ctr][1] = i;
				ctr++ ;
			}
		}
		for (i = 1; i < n-1; i++) {
			if (str[i][0] == '.') {
				arr[ctr][0] = i; arr[ctr][1] = 0;
				ctr++ ;
			}
		}
		if(n > 1) for (i = 0; i < m; i++) {
				if (str[n-1][i] == '.') {
				arr[ctr][0] = n-1; arr[ctr][1] = i;
				ctr++ ;
				}
			}
		if(m > 1) for (i = 1; i < n-1; i++) {
				if (str[i][m-1] == '.') {
				arr[ctr][0] = i; arr[ctr][1] = m-1;
				ctr++ ;
			}
		}

		if (n < 2 && m < 2) flag = 0;
		if (ctr != 2) flag = 0;

		ex = 0;
		if (flag) maze(arr[0][0], arr[0][1]);

		if(ex) printf("valid\n");
		else printf("invalid\n");
	}
	return 0;
}
