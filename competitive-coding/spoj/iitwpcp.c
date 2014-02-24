#include <stdio.h>

long long int gcd (long long int a, long long int b) {
	if(a - (a/b)*b == 0) return b;
	return gcd( b, a- (a/b)*b);
}

int main()
{

	int t;
	long long int n,i;
	long long int tmp;
	scanf("%d", &t);

	while(t--) {
		scanf("%lld", &n);

		if(n == 1) {printf("0\n"); continue;}
		tmp = n/2;

		for( i = tmp; i >= 1; i--) {
			if(gcd (n , i) == 1) {
				printf("%lld\n", i);
				break;
			}
		}
	}
	return 0;
} 
