#include<stdio.h>
int main()
{ long long int i,j,t,n,x,sum;

    scanf("%lld",&t);
    for(i=0;i<t;i++)   
    { sum =0; n=0;
    fflush(stdin);
     scanf("%lld",&n);
     for(j=0;j<n;j++)
     {x=0;
     scanf("%lld",&x);
     sum=(sum+x)%n;     
     }
     if((sum%n)==0)
    printf("YES\n");
    else
    printf("NO\n");
    }
return 0 ;
}
