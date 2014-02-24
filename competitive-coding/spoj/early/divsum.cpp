#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{ long long int i,j,t,sum,n;
 t=0;    
    scanf("%d",&t);
    for(i=0;i<t;i++)   
    {  sum=1;
      scanf("%lld",&n);
      printf("%lld\n",sqrt(n));
      for(j=2;j<n;j++)
      {  if((n%j)==0)
         sum+= j;
      }
      printf("%lld\n",sum);
    }
getch();
return 0 ;
}
