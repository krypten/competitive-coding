/*
 *  Author 			: Krypten
 *  Algorithm 		: Adhoc
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector <int> defence;
	vector<int> attack;

	do {
		int a, d, temp;
		cin >> a >> d;
		attack.clear();
		defence.clear();

		if (a == 0 && d == 0) {
			break;
		}

		for (int i = 0; i < a; i++) {
			cin >> temp;
			attack.push_back(temp);
		}

		for (int i = 0; i < d; i++) {
			cin >> temp;
			defence.push_back(temp);
		}

		sort(attack.begin(), attack.end());
		sort(defence.begin(), defence.end());

		bool flag = true;

		// logic
		if (attack[0] >= defence[1]) {
			flag = false;
		}
		
		if (flag) {
			cout << "Y\n";
		} else {
			cout << "N\n";
		}

	} while (true);
	return 0;
}
