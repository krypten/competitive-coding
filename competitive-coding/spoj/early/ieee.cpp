#include<stdio.h>
int main()
{ int tc;
  float n;
    scanf("%d",&tc);
    while(tc--)   
    { scanf("%f",&n);
      printf("%0.8f\n",n/(n+1));
    }
return 0 ;
}
