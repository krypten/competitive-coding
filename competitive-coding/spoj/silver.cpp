/*
 *  Author		: Krypten
 *  Algorithm	: Adhoc
 */

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int func(int n)
{
	int i = 0;
	while (n > 0) {
		n /= 2;
		i++;
	}
	return i;
}

int main()
{
	int t, n;
	//scanf("%d", &t);
	t = 1;
	while (t) {
		cin >> n;
		if (n == 0){
			break;
		}
		cout << func(n) - 1 << endl;

	}
	return 0;
}
