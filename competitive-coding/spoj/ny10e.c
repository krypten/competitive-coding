#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t;
	int i;
	int j;
	unsigned long long int tmp1;
	unsigned long long int tmp2;
	int n;
	int tmp3;
	long int ni = 362880;

	scanf("%d", &t);
	for (j = 0; j < t; j++) {
		tmp1 = 1;
		tmp2 = 1;
		scanf("%*d %d", &n);
		if (n < 13) {
			for (i = 0; i < n; i++) {
				tmp1 = tmp1*(10 + i);			
				tmp2 = tmp2*(i+1);
			}
			tmp1 = (tmp1/tmp2);
			printf("%d %llu\n", j+1,tmp1);
			continue;
		} else {
			tmp3 = n - 10;
			for (i = 0; i < 9; i++) {
				tmp1 = tmp1*(9 + n - i);
			}
			tmp1 = (tmp1/ni);
			printf("%d %llu\n", j+1,tmp1);
			continue;
		}
	}
	return 0;
}
