#include<stdio.h>
long long int gcd(long long int a, long long int b)
{
   if(b==0)
        return a;
   else
        return gcd(b,a%b);
}
int main()
{ unsigned long long int a,b;
        scanf("%lld %lld",&a,&b);
        printf("%lld\n",gcd(a,b));
return 0 ;
}
