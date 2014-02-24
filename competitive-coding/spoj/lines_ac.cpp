#include <cstdio>
#include <algorithm>

using namespace std;

struct point {
	int x,y;
};

struct slope {
	int dx,dy;
};

point array[3000];
slope slp[50000];

bool comp (const slope &p, const slope &q) {
	return (q.dx*p.dy > q.dy*p.dx);
}

bool equal (slope p, slope q) {
	return (q.dx*p.dy == q.dy*p.dx);
}

int main()
{
	int n;
	int i,j,k;

	while (1) {
		scanf("%d", &n);
		if(n == 0) break;

		for( i = 0; i < n; i++) {
			scanf("%d %d", &array[i].x, &array[i].y);
		}

		for (i = 0, k = 0; i < n-1; i++ ) {
			for (j = i+1; j < n; j++,k++) {
				slp[k].dx = array[i].x - array[j].x;
				slp[k].dy = array[i].y - array[j].y;

				if (slp[k].dy < 0) {
					slp[k].dx = -1*slp[k].dx;
					slp[k].dy = -1*slp[k].dy;
				}
				if (!slp[k].dy) {
					slp[k].dx = abs(slp[k].dx);
				}
			}
		}

		sort ( slp, slp + k, comp);
		j = 1;
		for (i = 1; i < k; i++) j += !equal(slp[i-1] , slp[i]);

		printf("%d\n", j);
	}
	return 0;
}
