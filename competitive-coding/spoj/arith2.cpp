/*
 *  Author 			: Krypten
 *  Algorithm 		: Adhoc
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		char ch = getchar();
		long long int ans = 0;
		long long int num1 = 0;
		char oper = 0;
		while (ch != '=') {
			if (ch >='0' && ch <= '9') {
				num1 = num1 * 10 + ch-'0';
			} else if (ch == '-' || ch == '+' || ch == '*' || ch == '/') {
				if (oper == 0) {
					ans = num1;
					oper = ch;
				} else {
                    if (oper == '+')
                        ans = ans + num1;
                    if (oper == '-')
                        ans = ans - num1;
                    if (oper == '*')
                        ans = ans * num1;
                    if (oper == '/')
                        ans = ans / num1;
					oper = ch;
				}
				num1 = 0;
			}

			ch = getchar();
		}
		if (ch == '=') {
			if (oper == 0) {
				ans = num1;
			} else {
				if (oper == '+')
					ans = ans + num1;
				if (oper == '-')
					ans = ans - num1;
				if (oper == '*')
					ans = ans * num1;
				if (oper == '/')
					ans = ans / num1;
			}
			num1 = 0;
		}
		cout << ans << endl;
	}
	return 0;
}
