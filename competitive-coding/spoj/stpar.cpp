/*
 *  Author 			: Krypten
 *  Algorithm 		: Adhoc
 */

#include <bits/stdc++.h>

using namespace std;

int arr[1024] = {0};
int main()
{
	int n;
	do {
		memset(arr, 0, sizeof(arr));
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		bool flag = true;
		stack <int> que;
		int ctr = 1;
		for (int i = 0; i < n; i++) {
			while (!que.empty() && que.top() == ctr) {
				ctr++;
				que.pop();
			}
			if (arr[i] == ctr) {
				ctr++;
			} else {
				if (!que.empty() && que.top() < arr[i]) {
					flag = false;
				} else {
						que.push(arr[i]);
				}
			}
		}

		if (flag) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	} while (true);
	return 0;
}
