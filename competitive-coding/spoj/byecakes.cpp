/*
 *  Author		: Krypten
 *  Algorithm	: Adhoc
 */

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, int> pii;
typedef vector<pii>::iterator vit;

struct comparator{
	bool operator()(const pii& a, const pii& b) {
		return b.second*a.first > a.second*b.first;
	}
};
int main()
{
	int t;
	double n;
	//scanf("%d", &t);
	t = 1;
	while (t) {
		vector <pii> v;
		for (int i = 0; i < 4; i++) {
			cin >> n;
			v.push_back(pii(n, 0));
		}
		bool flag = false;
		if (v[0].first == -1)
			flag = true;
		for (int i = 0; i < 4; i++) {
			cin >> n;
			v[i].second = n;
		}
		if (flag)
			break;
		vector <pii> f;
		f = v;
		sort(f.begin(), f.end(), comparator());
		
		int x = (int) (f[0].first + f[0].second - 1)/ f[0].second;
		//cout << *x << " " << ceil(*x)  << " " << v[0] << " " << f[0] << endl;
		cout << v[0].second*x - (v[0].first) << " " << v[1].second*x - (v[1].first) << " " <<  v[2].second*x - (v[2].first) << " " <<  v[3].second*x - (v[3].first) << " \n";  
	}
	return 0;
}