#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 100006
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
      for(i = 0; i<n;i++) printf("%d\n", s[i]);
}
int main()
{           scanf("%s", str);
            n = strlen(str);
            suffix_array();
      return 0;
}
