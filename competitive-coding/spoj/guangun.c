#include <stdio.h>
#include <math.h>

int main()
{
	unsigned long long int ans, x, var, var2;
	ans = 1;
	while (scanf("%llu", &x) != EOF) {
		var = x/9;
		var2 = x%9;
		ans = 81*var + var2*var2;
		printf("%llu\n", ans);
	}
	return 0;
}
