#include <stdio.h>

const int MOD = 1000000003;

inline long long int mod(long long int a) {
	return a < MOD ? a : a % MOD;
}

int main()
{
      unsigned long long int n;
      unsigned long long int t;
      unsigned long long int i;
      unsigned long long int sum;
      scanf("%llu", &t);
      while(t--) {
            unsigned long long int arr[6] = { 0, 4, 30, 50, 30, 6};
            unsigned long long int inv = 441666668;
            unsigned long long int p[6];
            sum = 0;
            scanf("%llu", &n);
    		for(i = 1, p[0] = 1; i <= 5; i++) p[i] = mod(n * p[i-1]);
		for(i = 1; i <= 5; i++) p[i] = mod(arr[i] * p[i]);
		for(i = 1, sum = 0; i <= 5; i++) sum = mod(sum + p[i]);
            sum = mod(sum * inv);
            printf("%llu\n", sum);
      }
      return 0;
}
