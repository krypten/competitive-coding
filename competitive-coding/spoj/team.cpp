#include <cstdio>
#include <algorithm>

int main()
{
      long long int ctr = 0;
      long long int ans = 0;
      long long int a[4];

      while(scanf("%lld %lld %lld %lld", &a[0], &a[1], &a[2], &a[3]) != EOF) {
            ctr++;
            std :: sort(a, a+4);
            ans = a[3] + a[2];
            printf("Case %lld: %lld\n" , ctr, ans);
      }
      return 0;
}
