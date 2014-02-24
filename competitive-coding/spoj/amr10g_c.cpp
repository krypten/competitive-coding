/* TODO:
      sort and then min differen in (0-n-k to k - n)
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

int main()
{
      int t;
      int i;
      int tmp;
      int mini;
      int n,k;
      vector <int> v;
      vector <int>:: iterator it;

      scanf("%d", &t);
      while(t--) {
            scanf("%d %d", &n, &k);
            //if ( k == 1) (printf("0\n");conitnue;}
            for(i = 0 ; i< n;i++ ) {
                  scanf("%d", &tmp);
                  v.push_back(tmp);}
            sort(v.begin(), v.end(),std::greater<int>());

            mini = INT_MAX;
            for ( i = 0; i<=n-k ;i++) {
                  if ( mini > (v[i]-v[i+k-1]) ) {
                        mini = v[i] - v[i+k-1]; }}

            printf("%d\n", mini);
            v.clear();
      }
      return 0;
}
