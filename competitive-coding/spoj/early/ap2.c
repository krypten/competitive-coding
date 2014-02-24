#include<stdio.h>
int main()
{ long long int i,j,x,y,d,a,sum,n;
 int t;
 t=0;    
    
    scanf("%d",&t);
    for(i=0;i<t;i++)   
    {  n=sum=x=y=0;
       scanf("%lld",&x);
       scanf("%lld",&y);
       scanf("%lld",&sum);
       n=(2*sum)/(x+y);
       printf("%lld\n",n);
       d=(y-x)/(n-5);
       a=x-(2*d);
       for(j=0;j<n;j++)
       printf("%lld ",(a + (j*d)));    
       printf("\n");
    }
return 0 ;
}
