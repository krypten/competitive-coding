#include <iostream>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

int main()
{
	int t;
	int size;
	int x;
	int y;
	int n;
	int ctr;
	int sum;

	set <int> s;
	map <int , int> m;
	ctr = 0;

	scanf("%d", &t);
	while(t--) {
		scanf("%d", &x);
		m.insert(pair <int, int> (ctr++, x) );
		scanf("%d", &n);
		while (n--) {
			scanf("%d", &y);
			s.insert(y);
		}
	}

	sum = s.size();
	map <int, int>::iterator it = m.begin();

	for ( ; it != m.end(); it++) {
		if(s.count(it->second) > 0)
			sum = sum - 1;
	}
	
	printf("%d\n", sum);
	return 0;
}
