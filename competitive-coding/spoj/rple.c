#include <stdio.h>

int main()
{
	int t;
	int n;
	int r;
	int x;
	int y;
	int i;
	int j;
	int flagsp;

	scanf("%d", &t);
	for(i =0; i < t; i++) {
      		int arr[10001] = {0};
		int arr2[10001] = {0};
      		flagsp = 0;
		scanf("%d %d", &n, &r);

      		for(j = 0; j<r;j++) {
			scanf("%d %d", &x, &y);
            		arr[x]++;
			arr2[y]++;
      		}

      		while (n--) {
            		if (arr[n] > 0 && arr2[n] > 0) {
				flagsp = 1;
                  		break;
            		} 
      		}

      		if (flagsp) {
            		printf("Scenario #%d: spied\n", i + 1);
     		 } else {
       		    	printf("Scenario #%d: spying\n", i+1);
      		}
	}
	return 0;
}
