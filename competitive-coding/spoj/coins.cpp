/*
 *  Author 			: Krypten
 *  Algorithm 		: Memoization + DP
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX 10000000

long long int arr[MAX];

long long int max (long long int a, long long int b)
{
    if (a > b)
        return a;
    return b;
}
long long int dp(long long int n)
{
	if (n <= 1) {
		return n;
	}
	if (n < MAX && arr[n] != 0) {
		return arr[n];
	}

	long long int ans = max(n, dp(n/2) + dp(n/3) + dp(n/4));
	if (n < MAX) {
        arr[n] = ans;
	}
	return ans;
}

int main()
{
	long long int n;
	while(scanf("%lld",&n)!=EOF) {
		memset(arr, 0, sizeof(arr));
		long long int ans = max(n, dp(n));
		cout << ans << endl;
	}
	return 0;
}
