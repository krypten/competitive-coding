#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 100024

int a[MAX];

inline int abso(int a) {
	return (a > 0)?a:-a ;
}

int main()
{
	long long int n, i;
	long long int ctr;
	long long int total;
	long long int work;

	while (1) {
		scanf("%lld", &n);
		if (n == 0) break; 
		work = 0;
		memset(a, 0, sizeof(a));

		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]); }

		//printf("DONE\n");
		total = 0;

		for (i = 0; i < n; i++) {
			if( a[i] == 0) continue;

			if(total == 0) {
				total = a[i];			
				ctr = (a[i]>0)? 1:-1;
				work = work + ctr*(a[i])*(n-i);

			} else if (ctr*a[i] > 0) {
				total = total + a[i];
				work = work + ctr*(a[i])*(n-i);
			} else { 
				if (abso(total) > abso(a[i])) {
					work = work + ctr*(a[i])*(n-i);
					total = total + a[i];
				} else {
					work = work + (ctr*(-total))*(n-i);
					a[i] = a[i] + total;
					total = 0;
					i--;
				}
			}
			//printf("%lld %lld\n", total, work);
		}
		printf("%lld\n", work);
	}
	return 0;
}
