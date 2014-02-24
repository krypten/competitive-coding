/* wrong answer */

#include <cstdio>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;

int main()
{
	int j;
	int i, n;
	int x,y;
	vector <pii> v;
	map <double, int> m;

	while (scanf("%d", &n) == 1 && n) {
		v.clear();
		m.clear();
		v.resize(n);

		for (i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			v[i] = pii (x,y);
		}

		for (i = 0; i < (n-1); i++) {
			for (j = i+1; j < n; j++) {

				double tmp;
				double tmpx = v[i].first - v[j].first;
				double tmpy = v[i].second - v[j].second;

				if (v[i].first == v[j].first)
					tmp = numeric_limits<double>::max();
				else {
					if (v[i].second < v[j].second) {
						tmpx = -1.0*tmpx;
						tmpy = -1.0*tmpy;
					}
					tmp = tmpy/tmpx;
				}
				//printf("%lf\n", tmp);
				m.insert(pair <double, int> (tmp,1));
			}
		}

		if (n == 1) printf("1\n");
		else 
		printf("%d\n", (int) m.size());
	}
	return 0;
}
