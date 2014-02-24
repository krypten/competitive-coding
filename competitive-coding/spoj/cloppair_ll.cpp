#include <cmath>
#include <cstdio>
#include <limits>
#include <algorithm>


#define INF numeric_limits<long long int>::max()

using namespace std;

typedef struct point {
	int x,y;
	int ind;
} point;

int r1, r2;
long long int best;
point *pointbyx;
point *pointbyy, *strip;

bool ord_x (const point &a, const point &b) {
	return a.x < b.x;
}
long long int sq(long long int a) {
	return a*a;
}

long long int euclid_dist(point p, point q) {
	return (sq(p.x - q.x) + sq(p.y - q.y));
}

bool ord_y(point p, point q) {
	if (p.y < q.y) return true;
	if (p.y > q.y) return false;
	return (p.x < q.x);
}

void merge (int low, int mid, int high) {
	int i, j, k;
	for (k = low; k<= high; k++) {
		strip[k] = pointbyy[k];
	}

	i = low;
	j = mid + 1;
	k = low;
	
	while (i <= mid && j <= high) {
		pointbyy[k++] = ord_y(strip[i], strip[j]) ? strip[i++]: strip[j++];
	}

	while (i <= mid) {
		pointbyy[k++] = strip[i++];
	}
}

long long int closestpair( int low, int high ) {
	int m; 
	int i, j;
	
	if (high <= low )
		return INF;

	int mid = (high-low)/2 + low;
	
	long long int delta1 = closestpair(low, mid);
	long long int delta2 = closestpair(mid+1, high);

	if (delta2 < delta1) {
		delta1 = delta2;
	}

	merge(low, mid, high); // sorts strip and point by Y

	m = 0;
	// stores all the point in strip in strip array;
	for (i = low; i <= high; i++) {
		if (sq((pointbyy[i].x - pointbyx[mid].x)) < delta1) {
			strip[m++] = pointbyy[i];
		}
	}
	
	long long int distance;

	for (i = 0; i < m; i++) {
		for(j = i+1; j < m && ((strip[j].y - strip[i].y) < delta1); j++) {
			distance = euclid_dist(strip[i], strip[j]);
			if (distance < delta1) {
				delta1 = distance;
				if (delta1 < best) {
					best = delta1;
					r1 = strip[i].ind;
					r2 = strip[j].ind;
				}
			}
		}
	}
	return delta1;
}

int main()
{
	int n, i;
	double besty;

	scanf("%d", &n);
	pointbyx = new point[n];

	for (i = 0; i < n; i++) {
		scanf("%d %d", &pointbyx[i].x, &pointbyx[i].y);
		pointbyx[i].ind = i;
	}

	if (n <= 1) return 0;

	sort (pointbyx, pointbyx + n-1, ord_x);

	pointbyy = new point[n];
	for (i = 0; i < n; i++)
		pointbyy[i] = pointbyx[i]; //
        strip = new point[n];		  // 

	best = INF;
	closestpair(0, n-1);

	if (r1 > r2) {
		i = r1;
		r1 = r2;
		r2 = i;
	}
	printf("%d %d ", r1, r2);

	besty = (sqrt((double) best));
	printf("%.6lf\n", besty);
	return 0;
}
