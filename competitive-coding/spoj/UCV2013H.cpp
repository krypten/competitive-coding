#include <cstdio>
#include <cstring>
#include <map>

#define MAX 256

int arr[MAX][MAX];
int n,m;

using namespace std;

int patch( int i, int j)
{
	int size;
	
	if (arr[i][j] == 0) return 0;

	size = 1;
	arr[i][j] = 0;

	if ((j+1) < m) {
 		size = size + patch(i, j+1);
	}
	if (i+1 < n) {
		size = size + patch(i+1, j);
	}
	if (j-1 >= 0) {
		size = size + patch(i, j-1);
	}
	if (i-1 >= 0) {
		size = size + patch(i-1, j);
	}

	return size;
}

int main()
{
	int i,j;
	int size;
	map <int, int> ma;
	map <int, int>::iterator it;

	while(1) {
		int ctr = 0;
		scanf("%d %d", &n, &m);
		if ( n == 0 && m == 0) break;

		for ( i = 0; i < n; i++) {
			for ( j = 0; j < m; j++){
				scanf("%d", &arr[i][j]); }}

		for ( i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {	
				if(arr[i][j] == 1) {
					ctr++;
					size = patch(i,j);
				//	printf("%d\n", size);

//c++ starts
			it = ma.find(size);
			if (it == ma.end()) {
				ma.insert(pair<int, int>  (size , 1));
			} else {
				it->second = it->second + 1;
			}

	}}}

//print
	printf("%d\n", ctr);
	for(it = ma.begin(); it != ma.end();it++) {
		printf("%d %d\n", it->first, it->second);
	}
	ma.clear();
	}
	return 0;
}
