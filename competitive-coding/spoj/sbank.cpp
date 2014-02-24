#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int t;
	int n;
	int tmp;
	char str[32];

	scanf("%d", &t);

	map<string , int >  m;
	map<string , int >:: iterator it;

	while(t--) {
		scanf("%d", &n);
		for ( int j = 0; j < n; j++) {
			string s;
			gets(str);
			s = str;
			if (  s == "") {j--; continue;}
			it = m.find(s);
			if ( it == m.end() ) {
				m.insert(pair<string, int> (s, 1) );
			} else {
				it->second = it->second + 1;
			}
		}
		for ( it = m.begin(); it != m.end(); it++) {
			cout<<it->first;
			printf(" %d\n", it->second);
		}
		printf("\n");
		m.clear();
	}
	return 0;
}
