#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

vector <pair<int, pii > > stu;
set <pii> excel;
set <pii> :: iterator iter, last;

int main()
{
	int n, t;
	int i, ans;
	int a, b, c;

	scanf("%d", &t);
	while (t--) {
		stu.clear();
		excel.clear();

		scanf("%d", &n);
		stu.resize(n);

		for (i = 0; i < n; i++) {
			scanf("%d %d %d", &a, &b, &c);
			stu[i] = (pair <int, pii > (a, pii(b,c)));
		}

		sort( stu.begin(), stu.end());
		
		excel.insert(stu[0].second);
		ans = 1;
		for (i = 1; i < n; i++) {
			b = stu[i].second.first ;
			c = stu[i].second.second;

			iter = excel.lower_bound(stu[i].second);
			if (iter  == excel.begin() || c < (--iter)->second) {
				ans++;
				excel.insert(stu[i].second);
				iter = excel.upper_bound(stu[i].second);
				for(; iter != excel.end();) {
					if(iter->first > b && iter->second > c) {
						last = ++iter;
						excel.erase(--iter);
						iter = last;
					}
					else break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
	sweep modified but sort first column and only better candidates put in set excel;
*/
