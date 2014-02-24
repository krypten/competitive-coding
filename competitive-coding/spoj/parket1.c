#include <stdio.h>
#include <math.h>

int main()
{
	double L, B, m, n;
	scanf("%lf %lf", &n, &m);
	B = ((n+4.0) + sqrt((n+4.0)*(n+4.0) - 16.0*(m+n))) / 4.0;
	L = (m+n) / B;
	if(L > B) printf("%.0lf %.0lf\n", L, B);
	else printf("%.0lf %.0lf\n", B, L);

	return 0;
}
