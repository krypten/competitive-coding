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

#define ull 		unsigned long long
#define ill 		long long int
#define pii 		pair<int,int>
#define pb(x) 		push_back(x)
#define F(i,a,n) 	for(int i=(a);i<(n);++i)
#define FI(i,a,n) 	for(i=(a);i<(n);++i)
#define FD(i,a,n) 	for(int i=(a);i>=(n);--i)
#define FE(it,x) 	for(it=x.begin();it!=x.end();++it)
#define V(x) 		vector<x>
#define S(x) 		scanf("%d",&x)
#define Sl(x) 		scanf("%llu",&x)
#define M(x,i) 		memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) 	((a)>(b)?(a):(b))

ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

int freq[26];
int main()
{
	string s, t;
	while(cin>>s>>t) {
		
		M(freq, 0);
		sort(t.begin(), t.end());
		F(i,0,s.size()) {
			freq[s[i] - 'a']++;
		}
		F(i,0,t.size()) {
			if (freq[t[i]-'a'] > 0) {
				cout << t[i];
				freq[t[i] - 'a']--;
			}
		}
		cout << endl;
		/*
		set<int>::iterator iS;
		for (iS = sS.begin(); iS != sS.end(); ++iS) {

			int temp = min(tT.count(*iS), sS.count(*iS));
			while (temp--) {
				ans = ans + char(*iS);
			}
		
			//cout << ans << " " << *iS << endl;
		}
		*/
	}
	return 0;
}