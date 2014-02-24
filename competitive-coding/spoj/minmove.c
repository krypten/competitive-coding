#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[400024];
int f[400024];
int len;


int lcs(char * str){
      int i;
      int j;
      int k;
      char * S;

      len = strlen(str);
      S = (char *)malloc(2*len*sizeof(char));
      strcpy(S, str);
      strcat(S, str);

      //printf("OK");

      memset(f, -1, sizeof(f));//f = [-1 for c in S]     # Failure function
      k = 0;  //     # Least rotation of string found so far
      for (j = 1; j < 2*len-1; j++ ) {
            i = f[j-k-1];
            while (i != -1 && S[j] != S[k+i+1]) {
                  if (S[j] < S[k+i+1]) {
                        k = j-i-1;}
                        i = f[i]; }
            if (i == -1 && S[j] != S[k+i+1]) {

                  if (S[j] < S[k+i+1]){
                        k = j;}
                        f[j-k] = -1;
            } else {
                  f[j-k] = i+1;}
      }
      return k;
}

int main()
{
      scanf("%s", str);
      printf("%d\n", lcs(str));
      return 0;
}
