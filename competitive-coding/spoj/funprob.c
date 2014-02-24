#include <stdio.h>

int main()
{
	int n;
	int m;
	double ans;
	while ( 1 ) {
		scanf("%d %d" , &n ,&m);
		if ( n == 0 ) {
			if ( m == 0) {
				break;
			} else {
				ans = 1;
			}
		} else if (m == 0) {
			ans = 0;
		} else {
			if ( n > m ) {
				ans  = 0;
			} else {	
				ans = ((m-n)+1.0) / (m+1);
			}
		}
		printf("%lf\n", ans);
	}
	return 0;
}
