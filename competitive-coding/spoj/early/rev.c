#include<stdio.h>
#define PRINT(int) printf("int = %d\n",int)
int main (int agrc,char **agrv )
{
int x=1, y=1, z=1 ,Y=1;
x=3; y=z=4;
PRINT(z >= y >= x ?1: 0);
return 0 ;
}
