#include <iostream>
#include <set>

using namespace std;

int main()
{
	int n;
	int key;
	int value;
	int t;
	int m;

	cin>>t;
	for (int j = 0; j < t ; j++ ) {

	cin>>m>>n;
	set <int> s, c;

	for ( int i = 0; i < n; i++) {
		cin>>key>>value;
		s.insert(key);
		c.insert(value);
	}

	int flag = 0;
	
	for (int i = 0; i <= m; i++) {
		if ( s.count(i) > 0 && c.count(i) > 0 ) {
			flag = 1;
			break;
		}
	}

	if (flag) {
		cout<<"Scenario #"<<j+1<<": spied\n";
	} else {
		cout<<"Scenario #"<<j+1<<": spying\n";
	}

	}
	return 0;
}
