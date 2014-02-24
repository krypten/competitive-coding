#include <cmath>
#include <cstdio>
#include <algorithm>

#define INF 1000000000

using namespace std;

typedef struct point {
	double x,y;
} point;

double best;
point *pointbyx, *array;
point *pointbyy, *strip;
point result1, result2;

bool ord_x (const point &a, const point &b) {
	return a.x < b.x;
}

double euclid_dist(point p, point q) {
	return sqrt((p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y));
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

double closestpair( int low, int high ) {
	int m; 
	int i, j;
	
	if (high <= low )
		return INF;

	int mid = (high-low)/2 + low;
	
	double delta1 = closestpair(low, mid);
	double delta2 = closestpair(mid+1, high);

	if (delta2 < delta1) {
		delta1 = delta2;
	}

	merge(low, mid, high); // sorts strip and point by Y

	m = 0;
	// stores all the point in strip in strip array;
	for (i = low; i <= high; i++) {
		if (abs(pointbyy[i].x - pointbyx[mid].x) < delta1) {
			strip[m++] = pointbyy[i];
		}
	}
	
	double distance;

	for (i = 0; i < m; i++) {
		for(j = i+1; j < m && ((strip[j].y - strip[i].y) < delta1); j++) {
			distance = euclid_dist(strip[i], strip[j]);
			if (distance < delta1) {
				delta1 = distance;
				if (delta1 < best) {
					best = delta1;
					result1 = strip[i];
					result2 = strip[j];
				}
			}
		}
	}
	return delta1;
}

int main()
{
	int n, i;
	int r1, r2;

	scanf("%d", &n);
	pointbyx = new point[n];
	array = new point[n];

	for (i = 0; i < n; i++) {
		scanf("%lf %lf", &pointbyx[i].x, &pointbyx[i].y);
	}

	for (i = 0; i < n; i++) {
		array[i] = pointbyx[i];
	}

	if (n <= 1) return 0;

	sort (pointbyx, pointbyx + n-1, ord_x);

	pointbyy = new point[n];
	for (i = 0; i < n; i++)
		pointbyy[i] = pointbyx[i]; //
        strip = new point[n];		  // 

	best = INF;
	closestpair(0, n-1);

	for (i = 0; i < n; i++) {
		if (array[i].x == result1.x && array[i].y == result1.y) {
			r1 = i; break;
		}
	}

	for (i = 0; i < n; i++) {
		if (array[i].x == result2.x && array[i].y == result2.y) {
			r2 = i; break;
		}
	}

	if ( r1 > r2) {
		i = r1;
		r1 = r2;
		r2 = r1;
	}
	printf("%d %d ", r1, r2);

	printf("%lf\n", best);
	return 0;
}
