#include <stdio.h>

long long int mod_exp( long long int a, long long int b) 
{
	long long int var = 1;
	long long int mult = a;
	
	while ( b > 0 ) {
		if ( b%2 == 1) {
			var  = var * mult % 1000000007;
		} 
		mult = mult * mult % 1000000007;
		b = b>>1;
	}
	return var;
}

int main()
{
	long long int sum, n, m;

	while (1) {
		scanf("%lld %lld", &n, &m);
		if ( n == 0 && m == 0) break;

		sum = 0;
		while (m > 0) {
			sum = sum + mod_exp(n,m);
			m--;
		} 
		sum = sum % 1000000007;
		printf("%lld\n", sum);
	}
	return 0;
}
