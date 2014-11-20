/*
 *  Author 		: Krypten
 *	Algorithm 	: Infix to Prefix Expression (prefectly bracketedwith only two oprends)
 */

#include <bits/stdc++.h>

using namespace std;

bool contains(char op, char * opArr, int n)
{
    for (int i = 0; i < n; ++i) {
        if (opArr[i] == op)
            return true;
    }
    return false;
}
void infixToPrefix(string& exp, string& result)
{
	string temp;
	stack<char> stk;
	stack<char> oper;
	char operArray[] = {'+', '-', '*', '/', '^'};
    int n = 5;

	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] == ')') {
			temp = "";
			while (stk.top() != '(') {
				temp = stk.top() + temp;
				stk.pop();
			}
			stk.pop();
			result = result + temp + oper.top();
			oper.pop();
		} else if (contains(exp[i], operArray, n)) {
			oper.push(exp[i]);
			temp = "";
			while (stk.top() != '(') {
				temp = stk.top() + temp;
				stk.pop();
			}
            result = result + temp;
		} else if (exp[i] != ' ') {
			stk.push(exp[i]);
		}
	}
}

int main ()
{
	int t;
	string result;
	string expression;

	cin >> t;
	while (t--) {
		result = "";
		cin >> expression;
		infixToPrefix(expression, result);
		cout << result << endl;
	}
	return 0;
}
