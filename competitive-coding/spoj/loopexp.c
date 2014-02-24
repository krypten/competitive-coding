#include <stdio.h>
#include <math.h>

int main()
{
	int t, i;
	int n;
	double tmp;
	double ans;

	scanf("%d", &t);
	
	while(t--) {
		scanf("%d", &n);
		ans = 1;
		tmp = n;

		for ( i = 1; i < n; i++) {
			ans = ans + 1.0/(i+1.0); 
		}

		printf("%lf\n", ans);
	}
	
	return 0;
}
