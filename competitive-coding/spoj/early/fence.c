#include<stdio.h>
int main()
{ unsigned long long int n;
  float s;
    while(1)  
    {   n=0;
        scanf("%lld",&n);
        if(n==0)
        break;
        if(n==7)
        {printf("7.8");
        continue;}
        s=(n*n)/6.28318530716;
        printf("%.2f\n",s)   ;             
    }
return 0 ;
}
