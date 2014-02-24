#include<stdio.h>
int main()
{ long long int i,j,tc,t1,t2,sum5,sum2,n;
 tc=0;    
    scanf("%d",&tc);
    for(i=0;i<tc;i++)   
    { j=0; t2=0; t1=0; sum5=0; sum2=0;
      scanf("%lld",&n);
      for(j=2;j<=n;j++)
    { t1=t2=j;
      while((t1%2)==0)
      { sum2++;
        t1=t1/2;
      }
      while((t2%5)==0)
      { sum5++;
        t2=t2/5;
      }
    }
    
      if(sum5>=sum2)
      printf("%lld\n",sum2);
      else
      printf("%lld\n",sum5);
      
    }

return 0 ;
}
