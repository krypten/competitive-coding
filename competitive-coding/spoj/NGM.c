#include <stdio.h>

int main()
{
      long int x;

      while(scanf("%ld", &x) != EOF) {
      if(x%10 != 0) {
            printf("1\n%ld", x%10);
      } else {
            printf("2\n");
      }}
      return 0;
}
