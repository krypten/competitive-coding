#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define LMAX 6001
int dp[LMAX];
char arr[LMAX];

long long int a_code(long long int i, long long int n)
{
      if (i >= n) return 1;
      if (dp[i]) return dp[i];
      if (arr[i] == '0') return 0;
      long long int re = 0;
      re += a_code(i + 1, n);
      if (i+1 < n && ((((int) arr[i] - 48) * 10 + ((int)arr[i+1]-48)) <= 26)) {
            re += a_code(i + 2, n);
      }
      return dp[i]=re;
}

int main()
{
      long long int n;
      scanf("%s", arr);

      while(arr[0] != '0') {
            n = strlen(arr);
            if(n == 1){
                  printf("1\n");
            } else {
            memset(dp, 0, sizeof dp);
                  printf("%lld\n", a_code(0, n));
            }
            scanf("%s", arr);
      }
      return 0;
}
