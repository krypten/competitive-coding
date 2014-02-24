#include <stdio.h>
#include <string.h>

int main()
{
      int t;
      long long int i;
      long long int n;
      char tmp1[4];
      char tmp2[4];

      scanf("%d", &t);

      while(t--) {
            scanf("%lld", &n);
            if ( n > 0)  {
                  scanf("%s", tmp2);
            }
            for ( i = 1; i < n; i++) {
                  scanf("%s", tmp1);
                  if(strcmp(tmp1 , tmp2) == 0){
                        strcpy(tmp2, "hhb");
                  } else{
                        strcpy(tmp2, "lxh");
                  }
            }
            printf("%s\n", tmp2);
      }
      return 0;
}
