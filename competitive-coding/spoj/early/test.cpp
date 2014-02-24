#include<stdio.h>

int main()
{ int a; int i=0;
 for(i=0;i<99;i++)
 {scanf("%d",&a);
 if(a==42)
 break;              
 printf("%d\n",a);
 };
return 0;
}
