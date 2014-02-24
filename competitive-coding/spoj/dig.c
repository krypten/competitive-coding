#include <stdio.h>

int main()
{
	int t;
	long long int n,ans,tmp, var;
	scanf("%d", &t);
	
	while(t--) {
		scanf("%lld", &n);
		var = n*(n-1)%1000000007;
		tmp = (n-2)*(n-3)%1000000007;
		ans = var*tmp%1000000007;
		ans = ans * 41666667%1000000007;

		printf("%lld\n", ans);
	}
	return 0;
}

