#include <stdio.h>

int main()
{
	int y;
	int x;
	int tc;
	
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%d %d",&x, &y);
		if (y == x || y== (x-2)) {
			if (y % 2 == 0) {
				printf("%d\n", 2*y + x - y);
			} else {
				printf("%d\n", 2*(y-1) + 1 + x - y);
			}

		}
		else {
			printf("No Number\n");

		}



	}


return 0;
}
