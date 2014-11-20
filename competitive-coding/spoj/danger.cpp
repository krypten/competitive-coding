/*
 *  Author		: Krypten
 *  Algorithm	: Josephus
 */

#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

int josephus_2(double n) {
	int c = 1;
	while (c <= n) {
		c <<= 1;
	}
	return (2*(n-(c>>1))+1);
}

int main()
{
	int t, n;
	//scanf("%d", &t);
	t = 1;
	while (t) {
		string str;
		cin >> str;
		n = (str[0] - '0')*10 + (str[1] - '0');
		if (n == 0)
			break;
		int z = str[3] -'0';
		while (z--) {
			n *= 10;
		}

		cout << josephus_2(n) << endl;

	}
	return 0;
}
