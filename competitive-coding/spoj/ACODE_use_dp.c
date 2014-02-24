#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LMAX 6001


void a_code(long long int * ptr, char * arr, long long int beg, long long int last)
{
      long long int i;
      for(i = beg; i < last; i++) {
            if (i+1 != last && arr[i+1] == '0') {
                  continue;
            } else if ((((int) arr[i-1]-48) != 0) &&(((int) arr[i]-48) != 0)&& ((((int) arr[i-1] - 48) * 10 + ((int)arr[i]-48)) <= 26)) {
                  *ptr += 1;
                  a_code(ptr, arr, i + 2, last);
            }
      }
}

int main()
{
      char * arr;
      long long int i;
      long long int n;
      long long int ctr;
      long long int inc;

      arr = (char *) malloc(LMAX*sizeof(char));
      scanf("%s", arr);

      while(arr[0] != '0') {
            ctr = 1;
            n = strlen(arr);
            if(n == 1){
                  printf("1\n");
            } else {
                  a_code(&ctr , arr,1, n);
                  printf("%lld\n", ctr);
            }
            scanf("%s", arr);
      }
      return 0;
}
