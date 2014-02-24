#include <stdio.h>

int main()
{
	int i, j;
	int n;
	long long int sum;
	int tmp;

	while ( 1 ) {
		scanf("%d", &n);
		
		if (n == 0) break;
		
		if (n%2 == 0) {
			i = n/2;
		} else {
			i = (n+1)/2;
		}
		sum = 0;
		for (j = 0 ;j<n;j++) {
			scanf("%d", &tmp);
			if ( j >= n-i) {
				sum  = sum + tmp;
			}
		}

		printf("%lld\n", sum);
	}
	return 0;
}
