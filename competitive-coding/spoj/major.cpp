#include <cstdio>

int main()
{
	int n;
	int t;
	int i;
	int tmp;

	scanf("%d" , &t);
	while (t--) {

	int arr[2048] = {0};
	int mx = 0;

	scanf("%d", &n);

	for ( i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if ( tmp > mx) mx = tmp;
		arr[tmp + 1024]++;
	}

	int flag = 0;

	for (i = mx + 1; i >-1000; i--) {
		if ( arr[i+1024] > (n+1)/2) {
			flag = 1;
			break;
		}
	}

	if (flag) {
		printf("YES %d\n", i);
	} else {
		printf("NO\n");
	}

	}
	return 0;
}
