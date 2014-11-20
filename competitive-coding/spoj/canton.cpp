/*
 *  Author 			: Krypten
 *  Algorithm 		: Adhoc (zig zag)
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	long long int n;
	long long int i, extra;
	long long int x, y;
	cin >> t;
	while (t--) {
		cin >> n;
		i = sqrt(2 * n);
		if (i * (i + 1) < 2 * n) {
			i++;
		}
		x = i;
		y = 1;
        //cout << "i is " << i << endl;

		extra = n - ((i-1) * (i)) / 2 - 1;

		//cout << "extra is " << extra << endl;
		x -= extra;
		y += extra;

		if (i % 2 == 0) {
			long long int temp = y;
			y = x;
			x = temp;
		}
		cout << "TERM " << n << " IS " << x << "/" << y << endl;
	}
	return 0;
}
