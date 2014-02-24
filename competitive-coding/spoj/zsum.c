#include <stdio.h>

long long int mod_exp( long long int a,long long int b){
    long long int odd;
    long long int q = 10000007;
    long long int val = 1;
    long long int mult = a;
    while (b > 0) {
        odd = b & 1;
        if (odd == 1) {
            val = (val * mult) % q;
            b -= 1;
        } if (b == 0) {
            break;
        }
        mult = (mult * mult) % q;
        b = b >> 1;
      }
    return val;
}

int main()
{
long long int n;
long long int k;
while (1) {
    scanf("%lld %lld", &n, &k);
    if (n == 0 && k == 0)
        break;
    printf("%lld\n",((mod_exp(n,k) + 2*mod_exp(n-1,k) + mod_exp(n,n) + 2*mod_exp(n-1,n-1))%10000007));
}return 0;
}

