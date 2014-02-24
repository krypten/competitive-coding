#include <stdio.h>
#include <string.h>

int main (int argc, char **argv)
{
	int i;
	int ctr1;
	int ctr3;
	int ctr2;
	int a;
	int b;
	int tc;
	int sum;

	ctr1 = ctr2 = ctr3 = 0;
	sum = 1;	
	
	scanf ("%d", &tc);
	for (i = 0; i<tc; i++)
	{
		scanf("%d/%d", &a, &b);
		
		if (a == 3) {
			ctr3++;
		} else if (b == 4) {
			ctr1++;
		} else {
			ctr2++;
		}
	}	
	
	if ( ctr3 >0 ) {
		if (ctr3 < ctr1) {
			ctr1 = ctr1 - ctr3;
			sum = sum + ctr3;
		} else {
			ctr1 = 0;
			sum = sum + ctr3;
		}
	}

	sum = sum + (ctr2 * 2 + ctr1 ) / 4 ;
	if (((ctr2 * 2 + ctr1 ) % 4) > 0)
		sum = sum + 1;

	printf("%d\n", sum);

	return 0;
}
