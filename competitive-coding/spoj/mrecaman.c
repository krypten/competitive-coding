#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[500004] = {0};
int ptr[3288004] = {0};

void func( int x) {
	int tmp;
	int l = 1;
	a[0] = 0;
	
	while ( l < x) {
		tmp = a[l-1] - l;
		if ( tmp <= 0 || ptr[tmp] == 1 ) {
			tmp = a[l-1] + l;
		}
		a[l] = tmp;
		//printf("%d %d\n", tmp, l);
		ptr[tmp] = 1;
		l++;
	}
}
		
int main()
{
	int n, ans;

	func (500004);
	while (1) {
		scanf("%d", &n);
		if ( n < 0) {
			break;
		}

		printf("%d\n", a[n]);
	}
	return 0;
}
