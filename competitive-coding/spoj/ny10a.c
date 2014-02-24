#include <stdio.h>

int main()
{
      int t;
      int n;
      int i;
      char str[41];
      scanf("%d", &t);
      while(t--) {
            int arr[8]={0};
            scanf("%d %s",&n, str);
            for ( i = 0; i < 38; i++) {
            if ( str[i] == 'H') {
                  if ( str[i+1] == 'H') {
                        if ( str[i+2] == 'H') {
                              arr[7]++;
                              continue;
                        } else {
                              arr[6]++;
                              continue;
                        }
                  } else {
                        if ( str[i+2] == 'H') {
                              arr[5]++;
                              continue;
                        } else {
                              arr[4]++;
                              continue;
                        }
                  }
            } else {
                   if ( str[i+1] == 'H') {
                        if ( str[i+2] == 'H') {
                              arr[3]++;
                              continue;
                        } else {
                              arr[2]++;
                              continue;
                        }
                  } else {
                        if ( str[i+2] == 'H') {
                              arr[1]++;
                              continue;
                        } else {
                              arr[0]++;
                              continue;
                        }
                  }
            }}
            printf("%d %d %d %d %d %d %d %d %d\n", n,arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]);
      }
      return 0;
}
