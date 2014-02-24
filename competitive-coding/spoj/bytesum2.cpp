#include <cstdio>
#include <climits>
#include <cstring>

int max(int a, int b)
{
      if ( a < b)
            return b;
      return a;
}

int dp[128][128];
int cost[128][128];
int n;
int m;

int solve(int pos, int level)
{
      if (level >= n) return 0;
      if (dp[pos][level] != -1) return dp[pos][level];
      int &ans = dp[pos][level]; ans = INT_MIN;
      if (pos+1 < m)
            ans  = max(ans, solve(pos+1, level+1) + cost[level][pos]);
      if (pos-1 >= 0)
            ans  = max(ans, solve(pos-1, level+1) + cost[level][pos]);
      ans  = max(ans, solve(pos, level + 1) + cost[level][pos]);
      return ans;
}

int main()
{
      int ans2;
      int i;
      int j;
      int t;
      scanf("%d", &t);
      while(t--) {
      scanf("%d %d", &n, &m);
      memset(dp, -1, sizeof dp);
      for( i = 0; i < n; i++) {
            for( j = 0; j < m; j++) {
                  scanf("%d", &cost[i][j]); }}
      ans2 = INT_MIN;
      for(i = 0; i < m; i++) {
            if (i+1 < m)
                  ans2  = max(ans2, solve(i+1, 1) + cost[0][i]);
            if (i-1 >= 0)
                  ans2  = max(ans2, solve(i-1, 1) + cost[0][i]);
            ans2  = max(ans2, solve(i, 1) + cost[0][i]);
      }

      printf("%d\n", ans2);
      }
      return 0;
}
