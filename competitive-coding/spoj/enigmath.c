#include <stdio.h>

int gcd(int a, int b) {
	if (a%b == 0) return b;
	return gcd(b, a%b);
}

int main()
{
	int t, i;
	int a, b;
	int x, y;
	int d;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);

		d = gcd (a, b);

		y = a/d;
		x = b/d;

		printf("%d %d\n", x, y);
	}
	return 0;
}
		
