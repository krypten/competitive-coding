#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int dp[20][3], cost[20][3];

int min(int a, int b)
{
      if ( a > b)
            return b;
      return a;
}

int fuc(int pos, int state, int n)
{
      if (pos == n) return 0;
      if (dp[pos][state] != -1) return dp[pos][state];
      int &ret = dp[pos][state]; ret = INT_MAX;
      for ( int i = 0; i < 3; i++) {
            if (i != state)
                  ret = min( ret, fuc(pos + 1, i, n) + cost[pos][state]);
      }
      return ret;
}

int main()
{
      int t;
      int n;
      int ans;
      cin>>t;

      while (t--) {
            ans = INT_MAX;
            cin>>n;
            for(int i = 0; i < n; i++) {
                  cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
            }
            memset(dp, -1, sizeof(dp));
            for(int i = 0; i < 3; i++)
                  ans = min(ans, fuc(0, i, n));
            cout<<ans<<"\n";
      }
      return 0;
}
