// Test Different test cases and test TODO:: ;
#include <cstdio>
#include <cstring>
#include <climits>

int n;
int v[4096] = {0};
int s[2048][2048] = {0};

int max( int a, int b)
{
      if ( b > a) return b;
      return a;
}

int solve ( int beg, int end, int age)
{
      if ( beg > end) {
            return 0;
      }
// TODO : Repeating Condition;;
      if (s[beg][end] != -1) return s[beg][end];

      int &ans = s[beg][end];
      ans = INT_MIN;

            ans  = max(ans, solve(beg+1, end, age+1)  + v[beg] * age);
            ans  = max(ans, solve(beg, end-1, age+1) + v[end] * age);

      //printf("%d\n", ans);

      return ans;
}

int main()
{
      int i;
      int ans;

      scanf("%d", &n);
      memset(s, -1, sizeof(s));
      for ( i = 0 ; i < n; i++ ) {
            scanf("%d", &v[i]);
      }

      ans = solve(0,n-1,1);

      printf("%d\n", ans);

      return 0;
}

/*
      if ( ans1 > ans2 ) {
            s[beg] = ans1;
            ans = ans1;
      } else {
            s[end] = ans2;
            ans = ans2;
      }
*/
