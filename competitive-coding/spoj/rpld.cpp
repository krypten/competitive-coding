#include <cstdio>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{

	int t;
	int n2, n;
	int key , value;
	map <int, set<int> > m;
	map <int, set<int> > :: iterator it;
	scanf("%d", &t);
	for (int j =0 ; j < t; j++) {
		int flag  = 1;
		scanf("%d %d", &n2, &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &key, &value);
			it = m.find(key);
			if (it == m.end()) {
				set <int> s;
				s.insert(value);
				m.insert(pair <int, set <int> > (key , s));
			} else {
				if(it->second.count(value) > 0)
					flag = 0;
				else 
					it->second.insert(value);
			}
		}
		if (flag) {
			printf("Scenario #%d: possible\n", j + 1);
		} else {	
			printf("Scenario #%d: impossible\n", j+1);
		}
		m.clear();
	}
	return 0;
}
