#include <stdio.h>

int main()
{
	int t;
	int n;
	int i;
	int j;
	int x;
	long long int sum;
	long long int min;

	scanf("%d" , &t);
	for( i = 0; i < t; i++) {
		sum = min = 0;
		scanf("%d", &n);
		for ( j = 0; j < n; j++) {
			scanf("%d", &x);
			sum = sum + x;
			if(sum < min) {
				min = sum;
			}
		}
		printf("Scenario #%d: %lld\n", i+1, (0 - min) + 1);
	}
	return 0;
}
