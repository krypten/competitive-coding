#include<stdio.h>

int main()
{ long long int i,tc,sum,n;
 tc=0;    
    scanf("%d",&tc);
    for(i=0;i<tc;i++)   
    { sum=0; n=0;
      scanf("%lld",&n);
      sum= (3*n*n + n)/2;
      printf("%lld\n",sum%1000007); 
    }

return 0 ;
}
