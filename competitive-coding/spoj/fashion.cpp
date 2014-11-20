/*
 *  Author        : Krypten
 *  Algorithm     : Adhoc
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int sum;
	vector<int> male;
	vector<int> female;
	int i,j,n,t;
	int temp;

	cin >> t;

	for (i = 0;i < t; i++) {
		n   = 0;
		sum = 0;
		cin >> n;
		male.clear();
		female.clear();

		for ( j = 0; j < n; j++) {
			cin >> temp;
			male.push_back(temp);
		}
		for ( j = 0; j < n; j++) {
			cin >> temp;
			female.push_back(temp);
		}
		sort(male.begin(), male.end());
		sort(female.begin(), female.end());
		for ( j = 0; j < n; j++) {
			sum+=male[j]*female[j];
		}
		cout << sum << endl;
	}

	return 0;
}
