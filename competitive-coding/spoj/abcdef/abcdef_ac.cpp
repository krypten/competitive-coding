#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector <int> v;
      vector <int> t;
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

	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n; j++ ) {
			for ( k = 0; k < n; k++ ) {
                        if(v[k]) {
                              tmp = (v[i]+v[j])*v[k];
                              t.push_back(tmp);
                        }
                  }
		}
	}

      sort(t.begin(), t.end());
	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n; j++ ) {
			for ( k = 0; k < n; k++ ) {
                        if(v[k]) {
                              tmp = v[i]*v[j] + v[k];
                              ans = ans + upper_bound(t.begin(), t.end(), tmp) - lower_bound(t.begin(), t.end(), tmp);
			}}
		}
	}

	printf("%d\n", ans);

	return 0;
}
