#include <stdio.h>

#define type long long int

int arr[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
int arr2[101] = {0};
int arr3[101] = {0};

type mod_exp (type a, type n, type q)
{
	type var = 1;
	type mult = a;
	while ( n != 0 ) {
		if (n%2 == 1) {
			var  = var * mult % q;
		}
		mult = mult * mult % q;
		n = n>>1;
	}
	return var;
}


int main()
{
	int t;
	int n;
	int r;
	int i;
	int tmp2;
	long long int ans = 1;

	i = 0;	
	scanf("%d %d", &n, &r);
	if( n < r) {
		printf("-1\n");
		return 0;
	}
	n--; r--;
	while (arr[i] <= n) {
		tmp2 = arr[i];
		i++;
		while(tmp2 <= n) {
			arr2[arr[i-1]] += n/tmp2;
			tmp2 = tmp2*arr[i-1];
		}
	}

	i = 0;
	while (arr[i] <= n-r) {
		tmp2 = arr[i];
		i++;
		while(tmp2 <= n-r) {
			arr3[arr[i-1]] += (n-r)/tmp2;
			tmp2 = tmp2*arr[i-1];
		}
	}
	i = 0;
	while (arr[i] <= r) {
		tmp2 = arr[i];
		i++;
		while(tmp2 <= r) {
			arr3[arr[i-1]] += r/tmp2;
			tmp2 = tmp2*arr[i-1];
		}
	}

	for(i = 2; i <= n; i++) {
		if(arr2[i] != 0)
		ans  = (ans * mod_exp(i, arr2[i] - arr3[i], 10000007)) % 10000007;
	}

		printf("%lld\n", ans);
	return 0;
}
