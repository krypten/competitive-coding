#include <stdio.h>
#include <math.h>

int main()
{
	int test, ctr = 0;
	double p0,p1,t,p;
	double ans;

	scanf("%d", &test);
	while(test--) {
		ctr++;
		scanf("%lf %lf %lf %lf", &p0, &p1, &t, &p);

		ans = t*(log10(p/p0))/log10(p1/p0);
		printf("Scenario #%d: %.2lf\n", ctr, ans);
	}
	return 0;
}
