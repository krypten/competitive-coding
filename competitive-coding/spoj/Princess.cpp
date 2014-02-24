#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;
long long int dp[1024];
long long int a[1024];

long long int solve(int pos,int n)
{
      if (pos == n || pos == (n+1)) return 0;
      if (dp[pos] != -1) return dp[pos];

      long long int &ret = dp[pos]; ret = INT_MIN;

      ret = max(ret, solve(pos + 2, n) + a[pos]);
      ret = max(ret, solve(pos + 1, n));

      return ret;
}
int main()
{
      int t;
      int i;
      int j;
      int n;
      long long int ans;
      scanf("%ld", &t);
      for (i = 0; i < t; i++) {
            scanf("%ld", &n);
            memset(dp, -1, sizeof dp);
            for(j = 0; j < n; j++) {
                  scanf("%lld", &a[j]);
            }
            if ( n == 0) {
                  printf("Case %d: 0\n", i+1);
                  continue;
            }
            ans = max(solve(1, n) , solve(2, n)+ a[0]);
            printf("Case %d: %lld\n",i+1, ans);
      }
      return 0;
}
