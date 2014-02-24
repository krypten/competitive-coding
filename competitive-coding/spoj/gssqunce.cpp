#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
      int t,i;
      int n, flag;
      int tmp;
      vector <int> a;

      scanf("%d", &t);
      while(t--) {

      scanf("%d", &n);

      for(i = 0; i < n; i++) {
            scanf("%d", &tmp);
            a.push_back(tmp);
      }

      std::sort(a.begin(), a.end());

      flag = 0;

      for(i = 2; i< n;i++) {
            if(a[i] == a[i-1] && a[i-1] == a[i-2]) {
                  flag = 1;
            }
      }

      if(flag || n == 1) {
            printf("NO\n");
      } else {
            printf("YES\n");
      }
      a.clear();
      }
      return 0;
}
