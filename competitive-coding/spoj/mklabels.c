#include <stdio.h>
unsigned long long int expe(long int a, long int b)
{
      long int val = 1;
      long int mult = a;
      while (b > 0) {
            if (b%2){
                  val = (val * mult);
            }
            mult = (mult * mult);
            b = b >> 1;
      }
      return val;
}

int main()
{
      int t;
      int i = 0;
      long int n;
      while(scanf("%ld", &n) != EOF) {
            if ( n == 0)  break;
            printf("Case %d, N = %ld, # of different labelings = %llu\n", ++i, n, expe(n, n-2));
      }
      return 0;
}
