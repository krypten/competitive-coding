#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	long long int x,y,z;
	double ans, tmp, var;

	scanf("%d", &t);
	while(t--) {
		scanf("%lld %lld %lld", &x, &y, &z);
		if ( y == 0 || x == z) {
			ans = x;
		} else {
			ans = z * x/(y + 2.0*z) + (z*sqrt(x*x + y*y + 2.0*z*y))/(y+2.0*z);
		}

		if ( ans - floor(ans) < 0.00000001) {
			printf("%.0lf\n", ans);
		} else {
			printf("Not this time.\n");
		}
	}
	return 0;
}
