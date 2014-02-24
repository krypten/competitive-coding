#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 1006
using namespace std;

char str[MAX];
int s[MAX];
int n;


int cmp(const void * a,const void * b) {
      return (strcmp((str + *((int*)a)),( str+ *((int*)b)))); }

void suffix_array() {
      int i;
      for(i = 0; i<n;i++) s[i]=i;
      qsort(s,n,sizeof(int), cmp);
}

long long int lcp(void) {
      char *x; char *y;
      int i;
      long long int cnt = 0;
      int p[MAX] = {0};
      x = str; y = str;

      for(i = 1; i < n; i++) {
            x = str + s[i-1];
            y = str + s[i];

            while(*x == *y) {
                  p[i]++;
                  x++; y++;
            }
            cnt += p[i];
      }
      return cnt;
}

int main()
{
      int t;
      long long int ans;
      long long int l;
      scanf("%d", &t);
      while(t--) {
            scanf("%s", str);
            n = strlen(str);
            suffix_array();
            ans = lcp();
            l = n;
            printf("%lld\n", (l*(l+1)/2) - ans);
      }
      return 0;
}
