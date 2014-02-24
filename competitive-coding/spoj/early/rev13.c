#include<stdio.h>
#define PRINT(int) printf("int = %d\n",int)
int main (int agrc,char **agrv )
{
int x, y, z;
x = y = z = -1 ;
++x && ++y || ++z; PRINT(x);
PRINT(z);
PRINT(y);
page 13 c Puzzle Book
return 0 ;
}
