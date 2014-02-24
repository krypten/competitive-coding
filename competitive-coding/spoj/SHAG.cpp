#include <cstdio>

long int arr[30000] = {0};

int main()
{
      long int t;
      long int d;
      long int gr = 0;
      scanf("%ld", &t);
      while(t--) {
            scanf("%ld", &d);
            arr[d] = 1;
            if((arr[d-1] != 0) && arr[d+1] != 0) {
                  gr--;
            } else if((arr[d-1] == 0) && arr[d+1] == 0) {
                  gr++;
            }
            printf("%ld\n", gr);
      }
      printf("Justice\n");
      return 0;
}
