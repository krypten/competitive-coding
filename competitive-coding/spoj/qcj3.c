#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	int r;
	int s;
	int x;
	int i;

	scanf("%d", &t);
	while (t--) {
		r = 0;
		scanf("%d", &s);
		for ( i = 1; i <= s; i++) {
			scanf("%d", &x);
			if(x&1) { r = r^i;};
		}
		printf("%s", (r==0)?"Hanks Wins\n":"Tom Wins\n");
	}
	return 0;
}
