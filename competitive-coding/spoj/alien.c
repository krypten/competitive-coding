#include <stdio.h>
#include <malloc.h>

int main()
{
	int n, m;
	int * arr;
	long long int sum, maxi;
	int i,j,t;
      int maxi_i;
      scanf("%d", &t);
      while(t--) {
	scanf("%d %d", &n, &m);

	arr = (int*) malloc(sizeof(int) *(n+1));

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	j  = 0;
	sum = arr[0];
	maxi = 0;
      maxi_i = 0;
	for ( i  = 1; i <= n; i++) {

		while (sum > m && j < i - 1) {
			sum = sum - arr[j];
			j++;
		}

		if(maxi_i == i-j && sum < maxi) {
                  maxi_i = i-j;
                  maxi = sum;
            }
            if(maxi_i < i-j) {
                  maxi_i = i-j;
                  maxi = sum;
            }

		if ( i < n) {
			sum = sum + arr[i];
		}
	}

	printf("%lld %d\n", maxi, maxi_i);
      }
	return 0;
}
