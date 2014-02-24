#include <stdio.h>
#include <malloc.h>

int main()
{
	int n, m;
	int * arr;
	long long int sum, maxi;
	int i,j;

	scanf("%d %d", &n, &m);

	arr = (int*) malloc(sizeof(int) *(n+1));

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	j  = 0;
	sum = arr[0];
	maxi = 0;
	for ( i  = 1; i <= n; i++) {
	
		while (sum > m && j < i - 1) {
			sum = sum - arr[j];
			j++;
		}

		if (sum < m && sum > maxi) {
			maxi = sum;
		}

		if ( sum == m ) {
			maxi = m;
			break;
		}
		
		if ( i < n) {
			sum = sum + arr[i];
		} 
	}

	printf("%lld\n", maxi);

	return 0;
}
