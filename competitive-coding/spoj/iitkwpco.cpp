#include <cstdio>
#include <algorithm>

int main()
{
	int t;
	int n;
	int i;
	int ans, j;
	int arr[128];

	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		
		for(i = 0 ; i < n; i++) {
			scanf("%d", &arr[i]);
		}
	
		std::sort(arr, arr + (n));
		ans = 0;

		for( i = 0; i < n; i++) {
			for( j = 0; j < n; j++) {
				if(arr[i] == 2*arr[j]) {
					ans++;
					arr[i] = arr[j] = 0;
					break;
				}
			}
		}
		printf("%d\n", ans); 	
	}
	return 0;
}	
