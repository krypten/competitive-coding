#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector <int> A;
	vector <int> B;
	vector <int> C;
	vector <int> D;
      vector <int> t;

	int a,b,c,d;
	int n, tmp;
	int i,j,k;
	int ans = 0;

	scanf("%d", &n);

	for ( i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}

	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n; j++ ) {
                  tmp = (A[i]+B[j]);
                  t.push_back(tmp);
            }
	}

      sort(t.begin(), t.end());

      for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n; j++ ) {
                  tmp = -(C[i] + D[j]);
                  ans = ans + upper_bound(t.begin(), t.end(), tmp) - lower_bound(t.begin(), t.end(), tmp);
		}
	}

	printf("%d\n", ans);

	return 0;
}
