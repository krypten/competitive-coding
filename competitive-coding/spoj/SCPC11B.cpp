#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
      int n,tmp,flag;
      vector <int> v;

      while(1) {
            scanf("%d", &n);
            if ( n == 0) break;

            for ( int i = 0;i < n; i++) {
                  scanf("%d", &tmp);
                  v.push_back(tmp);
            }

            sort(v.begin(), v.end());

            v.push_back(2844 - v.back());
            //printf("%d\n", v.back());

            flag = 0;
            for (int i = 1; i <= n; i++) {
                  if ((v[i] - v[i-1]) > 200) {
                        flag = 1;
                        break;
                  }}

            if ( flag ) {
                  printf("IMPOSSIBLE\n");
            } else {
                  printf("POSSIBLE\n");
            }
            v.clear();
      }
      return 0;
}
