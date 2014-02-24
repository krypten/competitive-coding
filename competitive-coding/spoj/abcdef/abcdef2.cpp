#include <cstdio>
#include <algorithm>
#include <vector>

int arr[100000000] = {0};

using namespace std;

int main()
{
	vector <int> v;
	vector <int> :: iterator it;
	int tmp;
	int n;
	int i,j,k;
	int ans = 0;

	scanf("%d", &n);

	for ( i = 0; i < n; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n; j++ ) {
			for ( k = 0; k < n; k++ ) {
				arr[(v[i]+v[j])*v[k] + 1000000] += 1 ;
				//printf("%d\n", (v[i]+v[j])*v[k] );
			}
		}
	}

	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n; j++ ) {
			for ( k = 0; k < n; k++ ) {
				tmp = v[i]*v[j] + v[k];
				if(arr[tmp + 1000000] > 0)  {
					ans = ans + arr[tmp + 1000000];
				//printf("%d %d %d %d\n", v[i], v[j], v[k], v[i]*v[j] + v[k]);
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
