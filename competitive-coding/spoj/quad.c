#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	double a, b, c, d;
	double tmp;
	double s;
	scanf("%d", &t);
	while (t--) {
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		s = (a + b + c + d)/2;
		tmp = sqrt((s-a)*(s-b)*(s-c)*(s-d));
		printf("%.2lf\n", tmp);
	}
	return 0;
}
