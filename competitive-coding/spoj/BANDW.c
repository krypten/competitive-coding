#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
      int ctr;
      int i;
      int n;
      char s[512];
      char t[512];
      while (scanf("%s %s", s, t) != EOF) {
            if ( s[0] == '*' && t[0] == '*')
                  break;
            n = strlen(s);
            ctr = 0;

            for ( i = 1; i<n; i++) {
                  if ((s[i] == t[i])&&(s[i-1] != t[i-1]))
                        ctr++;
            }
            if ( s[n-1] != t[n-1])
                  ctr++;
            printf("%d\n", ctr);
      }
      return 0;
}
