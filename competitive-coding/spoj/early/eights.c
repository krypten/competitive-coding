#include<stdio.h>
#include<conio.h>
int main()
{ long long int i,tc,sum,n;
 tc=0;    
    scanf("%d",&tc);
    for(i=0;i<tc;i++)   
    {   n=0;
        scanf("%lld",&n);
        printf("%lld\n",(n-1)*250+192)   ;             
    }
getch();
return 0 ;
}
