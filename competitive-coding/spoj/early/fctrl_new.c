#include<stdio.h>
int main()
{ long long int i,tc,t1,sum;
 tc=0;    
    scanf("%d",&tc);
    for(i=0;i<tc;i++)   
    { t1=0;sum=0;
      scanf("%lld",&t1);
      while(t1)
      { sum+=t1/5;
        t1=t1/5;
      } 
      printf("%lld\n",sum);
      
    }

return 0 ;
}
