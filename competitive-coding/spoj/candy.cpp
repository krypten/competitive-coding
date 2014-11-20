/*
 *  Author 			: Krypten
 *  Algorithm 		: Adhoc
 */

 #include <bits/stdc++.h>

 using namespace std;

 int main()
 {
 	int n;
 	int arr[100001];
 	do {
 		cin >> n;
 		if (n == -1) {
 			break;
 		}
 		if (n == 0) {
 			continue;
 		}
 		long long int sum = 0;
 		for (int i = 0; i < n; i++) {
 			cin >> arr[i];
 			sum += arr[i];
 		}
 		if (sum % n == 0) {
 			int ans = 0;
 			long long int avg = sum / n;
 			for (int j = 0; j < n; j++) {
 				if (arr[j] > avg) {
 					ans += (arr[j] - avg);
 				}
 			}
 			cout << ans << endl;
		} else {
			cout << "-1\n";
		}
 	} while (true);

 	return 0;
 }
