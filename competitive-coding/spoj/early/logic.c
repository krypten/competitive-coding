#include<stdio.h>
int main(int agrc , char **agrv)
{
    unsigned long long int n ,i,fac,sum;
    fac=1;
    sum=1;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    fac*=i;
    sum<<=n;
    printf("%lld\n",fac+sum-n);
    return 0;
}
