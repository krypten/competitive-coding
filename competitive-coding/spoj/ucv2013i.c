#include <stdio.h>
#include <math.h>

#define pi 3.14159265358979
int main()
{
	double n, r;
	double ans;
	
	while (1) {
		scanf("%lf %lf",&r, &n);
		if ( n == 0 && r == 0) break;
		ans = r / sin(pi/(2.0 * n));
		printf("%.2lf\n", ans);
	}
	return 0;
}	
