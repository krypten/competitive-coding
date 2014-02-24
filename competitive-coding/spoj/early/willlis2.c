#include<stdio.h>
#include<conio.h>
int main()
{ unsigned long long int i,n;
 i=0;n=0;    
    scanf("%lld",&n);
    while((n>1)&&((n%2)==0))                    
   { n=n/2; }  
    if(n<2)
    printf("TAK");                  
    else                   
    printf("NZE");  
    getch();
return 0 ;

}

