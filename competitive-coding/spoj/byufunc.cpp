#include <iostream>
#include <string>
#include <cstdio>

int main()
{
      char n1[100000], v1[100000], n2[100000], v2[100000];
      scanf("%s", n1 );
      scanf("%s", v1 );
      scanf("%s", n2 );
      scanf("%s", v2 );
      printf("The %s %s down the mountain while the %s %s up the mountain.\n", n1 , v1 , n2 , v2 );
      fflush(stdin);
      return 0;
}
