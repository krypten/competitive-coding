#include<stdio.h>
#include<conio.h>
int main()
{ signed long int a1,a2,a3,c,n;
     
   while(1)
   { c=0;a1=0;a2=0;a3=0;
    scanf("%ld",&a1);
    scanf("%ld",&a2);
    scanf("%ld",&a3);
    if ((a1==a2)&&(a2==a3)&&(a3==0))
    break;
     
     if((2*a2)==(a1+a3))
     {   printf("AP ");  
         c = a2 - a1;
         printf("%ld\n",(a3 + c));               
     } 
     else if((a2*a2)==(a1*a3))
     {   printf("GP ");  
         c=a2/a1;
         printf("%ld\n",(a3*c));               
     }                  
      
    }
getch();
return 0 ;
}
