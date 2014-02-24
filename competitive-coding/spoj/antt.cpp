/* 
	intersection and union set algo 
*/

#include <cstdio>
#include <vector>

using namespace std;

struct point {
	int x, y;
};

struct line {
	point p,q;
};

vector <line> v;

int turn ( point p, point q, point r) {
	int result = (r.x - p.x)*(q.y - p.y) - (r.y - p.y)*(q.x - p.x);

	if (result < 0) return -1;
	if (result > 0) return 1;
	return 0;
}

int checkpoint( point p, point q, point r) {
	return ( ((p.x <= r.x && r.x <= q.x) || (q.x <= r.x && r.x <= p.x)) && ((p.y <= r.y && r.y <= q.y) || (q.y <= r.y && r.y <= p.y)) );
}

bool intersect( line l1, line l2) {
	int tmp1, tmp2, tmp3, tmp4;
	
	tmp1 = turn(l1.p, l1.q, l2.p);
	tmp2 = turn(l1.p, l1.q, l2.q);

	tmp3 = turn(l2.p, l2.q, l1.p);
	tmp4 = turn(l2.p, l2.q, l1.q);

	if ( (tmp1*tmp2) < 0 && (tmp3*tmp4) < 0) {
			return true;
	}

	if(!tmp1 && checkpoint(l1.p, l1.q, l2.p)) return true;
	if(!tmp2 && checkpoint(l1.p, l1.q, l2.q)) return true;
	if(!tmp3 && checkpoint(l2.p, l2.q, l1.p)) return true;
	if(!tmp4 && checkpoint(l2.p, l2.q, l1.q)) return true;
	return false;
}

vector <int> pset(1024);

void initset(int siz) {
	pset.resize(siz+1);
	for( int i = 0; i < siz+1; i++) {
		pset[i] = i;
	}
}

int findset(int i) {
	return (pset[i] == i) ? i : (pset[i] = findset(pset[i]));
}

void unionset(int i, int j) {
	pset[findset(i)] = findset(j);
}

bool sameset( int i, int j) {
	return findset(i) == findset(j);
}

void solve (int n) {
	int i, j;

	initset(n);

	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			if(i != j && sameset(i,j) == false) {
				if(intersect(v[i] , v[j]) == true) {
					unionset(j , i);
				}
			}
		}
	}
}

int main()
{
	int i;
	int n, m, t;
	int src, dest;

	line tmp;

	scanf("%d", &t);

	while (t--) {
		v.clear();
		pset.clear();

		scanf("%d %d", &n, &m);

		for( i = 0; i < n; i++) {
			scanf("%d %d %d %d", &tmp.p.x, &tmp.p.y, &tmp.q.x, &tmp.q.y);
			v.push_back(tmp);
		}

		solve(n);
		
		for( i = 0; i < m; i++) {
			scanf("%d %d", &src , &dest);

			if(sameset(src-1 , dest-1)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
	return 0;
}	
