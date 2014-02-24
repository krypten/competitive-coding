#include<stdio.h>
#include<conio.h>
int main()
{ long long int sum;
int n;
    while(1)   
    { scanf("%d",&n);
    if(n==0)
    break;
      sum=n*(n+1)*(2*n+1);
      printf("%lld\n",sum/6);  
    }
getch();
return 0 ;
}
