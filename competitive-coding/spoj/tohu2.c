#include<stdio.h>

int main()
{
    char u;
    char ar2[10]={0};
    int tc;
    int j;
    int x;
    int i;
    int flag2;
    scanf("%d",&tc);
    while(tc--) {
            j = 0;
            flag = 0;
            for (i = 1; i < 100; i++) {
                  scanf("%d %c", &x, &u);
                  if ( x%9 == 0 && x < 90) {
                        ar2[j++] = u;
                  }
            }
            flag2 = 1;
            for (i = 0; i < 8; i++) {
                  if(ar2[i] != ar2[i+1]) {
                        flag2 = 0;
                  }
            }
            if((flag2 == 0)) {
                  printf("NO\n");
            } else {
                  printf("YES\n");
            }

      }
return 0 ;
}
