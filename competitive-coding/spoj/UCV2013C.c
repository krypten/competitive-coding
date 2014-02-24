#include <stdio.h>

int main()
{
	long long int d,f,b,m;
	long long int var,ans;

	while(1) {
		scanf("%lld %lld %lld %lld", &d, &f, &b, &m);

		if ( f == 0 && d == 0 && b == 0 && m == 0) break;

		var = f + 1 + (f*(f-1))/2;
		var = var*b;
		
		ans = d - var;
		if ( ans >= m) {
			printf("Farmer Cream will have %lld Bsf to spend.\n", ans);
		} else {
			printf("The firm is trying to bankrupt Farmer Cream by %lld Bsf.\n", m-ans);
		}
	}
	return 0;
}
