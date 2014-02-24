#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int main()
{
      unsigned long long int sum;
      long long int tmp,n,i;
      long long int v[100000];
      long long int a[100000];
      while(1) {
            scanf("%lld", &n);
            if(n == 0) break;
            for (i = 0; i< n; i++) {
                  scanf("%lld", &v[i]);
            }
            for (i = 0; i< n; i++) {
                  scanf("%lld", &a[i]);
            }
            sort(v, v + n);
            sort(a, a + n, greater <long long int >());

            sum = 0;
            for (i = 0; i< n; i++) {
                  sum = sum + v[i]*a[i];
            }

            printf("%lld\n", sum);
      }
      return 0;
}
