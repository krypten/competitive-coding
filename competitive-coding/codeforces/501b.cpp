/*
 *  Author		: Krypten
 *  Algorithm	: Adhoc
 */

#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

#define INF INT_MAX/2
#define ONLINE_JUDGE 1

#define ull 		unsigned long long
#define ill 		long long int
#define pii 		pair<int,int>
#define pb(x) 		push_back(x)
#define mp make_pair
#define F(i,a,n) 	for(int i=(a);i<(n);++i)
#define FI(i,a,n) 	for(i=(a);i<(n);++i)
#define FD(i,a,n) 	for(int i=(a);i>=(n);--i)
#define FE(it,x) 	for(it=x.begin();it!=x.end();++it)
#define V(x) 		vector<x>
#define S(x) 		scanf("%d",&x)
#define Sf(x) 		scanf("%lf",&x)
#define Ss(x)		scanf("%s", x)
#define P(x) 		printf("%d",x)
#define Ps(x)		printf("%s", x)
#define M(x,i) 		memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) 	((a)>(b)?(a):(b))
#define MIN(a,b) 	((a)>(b)?(b):(a))
#define LSOne(S) 	(S & (-S))

ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

void input() {
#if !ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}
	vector<string> vec, result;
	map<string,string> M;

void dfs() {
	map<string, bool> visited;
	vector<string>::iterator it;
	for (it = vec.begin(); it != vec.end(); ++it) {
		string first = *it;
		string second = *(++it);

		if (visited.find(first) != visited.end()) {
			continue;
		}

		result.pb(first);
		/*
		F(i,0, (int)result.size()) {
			Ps(result[i].c_str()),Ps(" ");
		} 
		Ps("\n");
		*/
		map<string, string>::iterator itM ;
		while ((itM = M.find(first)) != M.end()) {
			visited.insert(mp(first, false));
			first = (*itM).se;
		}
		result.pb(first);
	}
}

int main()
{
	input();
	int t;
	int temp;
	int n, m;
	char oldName[32], newName[32];
	//S(t);
	t = 1;

	map<string, bool> freq;
	while (t--) {
		M.clear();
		vec.clear();
		freq.clear();
		result.clear();
		S(n);
		F(i, 0 ,n) {
			Ss(oldName), Ss(newName);
			//if (M.find(oldName) == M.end())
			if (freq.find(newName) == freq.end()) {
				M.insert(mp(oldName, newName));
				vec.push_back(oldName);
				vec.push_back(newName);

				freq.insert(mp(oldName, true));
				freq.insert(mp(newName, true));
			}
		}
		dfs();
		P((int)result.size()/2), Ps("\n");
		for (int i = 0; i < (int)result.size(); i += 2) {
			Ps(result[i].c_str()),Ps(" "), Ps(result[i+1].c_str()),Ps("\n");
		}
	}
	return 0;
}
