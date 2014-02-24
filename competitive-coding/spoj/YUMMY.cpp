long int a[] = {1, 1, 1, 4, 6, 19, 43, 120, 307, 866, 2336, 6588, 18373, 52119, 147700, 422016, 1207477, 3471067, 9999135, 28893560};
#include <cstdio>

int main()
{     int t;
      int n;
      int ctr;
      ctr=0;
      scanf("%d", &t);
      while (t--) {
            ctr++;
            scanf("%d", &n);
            printf("Case #%d: %ld\n", ctr,a[n-1]);
      }
      return 0;
}
