#include<stdio.h>
int main()
{ unsigned long long int i,n;
 i=0;n=0;    
    scanf("%lld",&n);
    if(n<2)   
   { printf("TAK");    
    i=1;}                    
    while(n>0)                    
     {
        if(n==1)
        {printf("TAK");
        i=1;}
        if(n%2==0)
        n=n/2;    
        else
        break;
     }                   
    
    if(i!=1)                    
    printf("NZE");  
   ;

return 0 ;
}
