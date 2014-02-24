#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector <int> v;
	vector <int> t;
	vector <int> :: iterator it;
	int tmp;
	int n;
	int i,j,k;
	int ans = 0;

	scanf("%d", &n);

	for ( i = 0; i < n; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	
	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n; j++ ) {
			for ( k = 0; k < n; k++ ) {
				t.push_back( (v[i]+v[j])*v[k] );
				printf("%d\n", (v[i]+v[j])*v[k] );
			}
		}
	}

	sort( t.begin(), t.end() );

	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n; j++ ) {
			for ( k = 0; k < n; k++ ) {
				//it = ;
				if(binary_search(t.begin(), t.end(), v[i]*v[j] + v[k])) {
					ans++;
				printf("%d %d %d %d\n", v[i], v[j], v[k], v[i]*v[j] + v[k]);
				}
			}
		}
	}

	printf("%d\n", ans);
	
	return 0;
}

/*
You are given a set S of integers between -30000 and 30000 (inclusive).

Find the total number of sextuples  that satisfy: 

a*b + c/d -e = f 

a*b+c = (f+e)*d

Input

The first line contains integer N (1 ≤ N ≤ 100), the size of a set S.

Elements of S are given in the next N lines, one integer per line. Given numbers will be distinct.
Output

Output the total number of plausible sextuples.
Examples

Input:
1
1

Output:
1

	

Input:
2
2
3

Output:
4

	

Input:
2
-1
1

Output:
24

	

Input:
3
5
7
10

Output:
10

*/

