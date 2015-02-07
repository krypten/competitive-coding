/*
 *  Author		: Krypten
 *  Algorithm	: Segment Tree
 					leftValue -> starting to left index continuous sum
 					rightValue -> starting from right index to ending of array continuous sum
					sum -> sum of all elements in given range.
 					maxRSum -> maximum sum x <= i <= j <= y
 */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

#define INF 1000000000
#define ONLINE_JUDGE 1

#define ull 		unsigned long long
#define ill 		long long int
#define pii 		pair<int,int>
#define pb(x) 		push_back(x)
#define F(i,a,n) 	for(int i=(a);i<(n);++i)
#define FI(i,a,n) 	for(i=(a);i<(n);++i)
#define V(x) 		vector<x>
#define S(x) 		scanf("%d",&x)
#define Ss(x)		scanf("%s", x)
#define P(x) 		printf("%d",x)
#define Ps(x)		printf("%s", x)
#define M(x,i) 		memset(x,i,sizeof(x))
#define LSOne(S) 	(S & (-S))

ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

void input() {
#if !ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
}

//  Logic Starts here
const int MAX_ELEM = 1 << 16;;
#define INVALID_VALUE (INF + 1)

struct Tree {
	int leftVal;
	int rightVal;
	int sum;
	int maxRSum;
};

int arr[MAX_ELEM];
Tree tree[MAX_ELEM<<1];

inline int max2(int a, int b) {
	return ((a > b)? a : b);
}

inline int max3(int a, int b, int c) {
	return max2(a, max2(b, c));
}

void init(int index, int leftLimit, int rightLimit) {
	if (leftLimit == rightLimit) {
		tree[index].leftVal = tree[index].rightVal = tree[index].sum = tree[index].maxRSum = arr[leftLimit];
		return ;
	}

	int mid = (leftLimit + rightLimit) / 2;
	init(index*2, leftLimit, mid);
	init(index*2 + 1, mid + 1, rightLimit);

	tree[index].sum = tree[index*2].sum + tree[index*2 + 1].sum;
	tree[index].maxRSum = max3(tree[index*2].maxRSum , tree[index*2].rightVal + tree[index*2 + 1].leftVal, tree[index*2 + 1].maxRSum);
	tree[index].leftVal = max2(tree[index*2].leftVal, tree[index*2].sum + tree[index*2 + 1].leftVal);
	tree[index].rightVal = max2(tree[index*2].rightVal + tree[index*2 + 1].sum, tree[index*2 + 1].rightVal);
}

Tree query(int index, int leftLimit, int rightLimit, int i, int j) {
	// cout << leftLimit << " " << rightLimit << " " << i << " " << j << "\n";
	if (i > j) return tree[0];
	if (leftLimit == i && rightLimit == j) {
		return tree[index];
	}
	int mid = (leftLimit + rightLimit) / 2;
	if (j <= mid) return query(index*2, leftLimit, mid, i, j);
	if (i > mid) return query(index*2 + 1, mid + 1, rightLimit, i, j);
	else {
		Tree result;

		Tree leftSubRange = query(index*2, leftLimit, mid, i, mid);
		Tree rightSubRange = query(index*2 + 1, mid + 1, rightLimit, mid + 1, j);

		result.sum = leftSubRange.sum + rightSubRange.sum;
		result.maxRSum = max3(leftSubRange.maxRSum , leftSubRange.rightVal + rightSubRange.leftVal, rightSubRange.maxRSum);
		result.leftVal = max2(leftSubRange.leftVal, leftSubRange.sum + rightSubRange.leftVal);
		result.rightVal = max2(leftSubRange.rightVal + rightSubRange.sum, rightSubRange.rightVal);

		return result;
	}
}

int queryExtended(int leftLimitI, int rightLimitI, int leftLimitJ, int rightLimitJ, int n) {
	int result = 0;
	if (rightLimitI < leftLimitJ) {
		Tree leftSubRange = query(1, 0, n-1, leftLimitI, rightLimitI);
		Tree rightSubRange = query(1, 0, n-1, leftLimitJ, rightLimitJ);
		int midSubRangeSum = query(1, 0, n-1, rightLimitI + 1, leftLimitJ - 1).sum;
		// cout << leftSubRange.rightVal << " : " << midSubRangeSum << " : " << rightSubRange.leftVal << "\n";
		result = leftSubRange.rightVal + midSubRangeSum + rightSubRange.leftVal;
	} else {
		Tree leftSubRange = query(1, 0, n-1, leftLimitI, leftLimitJ - 1);
		Tree rightSubRange = query(1, 0, n-1, rightLimitI + 1, rightLimitJ);
		result = max3(leftSubRange.rightVal + query(1, 0, n-1, leftLimitJ, rightLimitJ).leftVal,
						query(1, 0, n-1, leftLimitI, rightLimitI).rightVal + rightSubRange.leftVal,
						query(1, 0, n-1, leftLimitJ, rightLimitI).maxRSum);
	}
	return result;
}

void printTree(int n) {
	int ctr = 1;
	int i = 1;
	while (ctr < n) {
		F(j, ctr, ctr+i) {
			if ((j-ctr) >= n) {
				break;
			}
			P(tree[j].sum),Ps(" ");
		}
		ctr += i;
		Ps("\n");
		i = i << 1;
	}
}

int main() {
	input();
	int n;
	int x1, y1;
	int x2, y2;
	int cntQuery;
	int testCases;

	S(testCases);
	while (testCases--) {
		S(n);
		F(i,0,n)
			S(arr[i]);

		tree[0].leftVal = tree[0].rightVal = tree[0].sum = tree[0].maxRSum = 0;
		init(1, 0, n-1);
		// printTree(n);
		S(cntQuery);
		while(cntQuery--) {
			S(x1), S(y1);
			S(x2), S(y2);

			int result = queryExtended(x1 - 1, y1 - 1, x2 - 1, y2 - 1, n);
			P(result),Ps("\n");
		}
	}
	return 0;
}
