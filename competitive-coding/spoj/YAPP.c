#include <stdio.h>

long long int mod_exp( long long int a,long long int b){
    long long int odd;
    long long int q = 1000000007;
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
int t;
scanf("%d", &t);
while (t--) {
    scanf("%lld", &n);
    if (n == 0)
        break;
    printf("%lld\n",(mod_exp(2,n-1)%1000000007));
}return 0;
}
