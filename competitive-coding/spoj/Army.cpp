#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int t;
	int m;
	int n;
	int tmp;
	int max1;
	int max2;

	scanf("%d", &t);
	
	while(t--) {
		max1 = max2 = 0;
		scanf("%d %d", &m, &n);
		for (int i= 0; i < m; i++) {
			scanf("%d", &tmp);
			if(max1 < tmp) {
				max1 = tmp;
			}
		}
	
		for (int i= 0; i < n; i++) {
			scanf("%d", &tmp);
			if(max2 < tmp) {
				max2 = tmp;
			}
		}
		if ( max1>= max2) {	
			printf("Godzilla\n");
		} else {
			printf("MechaGodzilla\n");
		}

	}
	return 0;
}

