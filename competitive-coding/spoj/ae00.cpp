/*
 *  Author 			: Krypten
 *  Algorithm 		: number of pairs (c,d) of integers such that 0 < c <= d and c*d <= n
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = (n+1)/2;
	for (int i = 1; i <= n/2; i++) {
		for (int j = 1; j <= i; j++) {
			if ((i * j) <= n)
				ans++;
		}
	}

	cout << ans << endl;
	return 0;
}
