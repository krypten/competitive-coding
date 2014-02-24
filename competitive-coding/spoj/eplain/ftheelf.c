#include <stdio.h>
#include <math.h>

int main()
{
	double n,h,v;
	double g = 9.80;
	double ans;

	while (1) {
		scanf("%lf %lf", &v , &h);
		if ( h == -1 && v == -1) break;
		if ( v == 0 ) {
			ans = 0;
		} else if ( h == 0) { 
			ans = v * v / g;
		} else {
			ans = (v*v/g/tan(asin(v/sqrt(2.0*g*h+2.0*v*v))));
		}

		printf("%.6lf\n", ans);
	}
	return 0;
}
