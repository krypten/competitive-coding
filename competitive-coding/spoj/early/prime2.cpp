#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{ long long int j,tc,ctr,n,m;
  int flag;
  long double i;
 tc=0;i=2130;
    scanf("%d",&tc);
    while(tc--)   
    {   ctr=1; 
        scanf("%lld %lld",&n,&m) ;
        printf("%lld %lld",n,m) ;              
         for(i=m;i<=n;i+=ctr)
         {   flag=1;
             cout<<sqrtl(i);
             if (((long long int)i)%2!=0)
             ctr=2;
             for(j=0;j<sqrtl(i);j++)
             {    cout<<sqrtl(i)<<"\n";            
                 if(((long long int)i)%j==0)
                 {flag=0;
                 break;}
             }
             if(flag)
             cout<<i<<"\n";
         }      
         
             
    }
getch();
return 0 ;
}
