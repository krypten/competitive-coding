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
	if (leftLimit == i && rightLimit == j) {
		return tree[index];
	}
	int mid = (leftLimit + rightLimit) / 2;
	if (j <= mid) return query(index*2, leftLimit, mid, i, j);
	if (i > mid) return query(index*2 + 1, mid + 1, rightLimit, i, j);
	else {
		Tree result;

		Tree leftSubTree = query(index*2, leftLimit, mid, i, mid);
		Tree rightSubTree = query(index*2 + 1, mid + 1, rightLimit, mid + 1, j);

		result.sum = leftSubTree.sum + rightSubTree.sum;
		result.maxRSum = max3(leftSubTree.maxRSum , leftSubTree.rightVal + rightSubTree.leftVal, rightSubTree.maxRSum);
		result.leftVal = max2(leftSubTree.leftVal, leftSubTree.sum + rightSubTree.leftVal);
		result.rightVal = max2(leftSubTree.rightVal + rightSubTree.sum, rightSubTree.rightVal);

		return result;
	}
}

void update(int index, int leftLimit, int rightLimit, int indexUpdateReq, int newValue) {
	// cout << leftLimit << " " << rightLimit << " " << i << " " << j << "\n";
	if (leftLimit == rightLimit && leftLimit == indexUpdateReq) {
		tree[index].leftVal = tree[index].rightVal = tree[index].sum = tree[index].maxRSum = arr[index] = newValue;
		return ;
	}

	int mid = (leftLimit + rightLimit) / 2;
	if (indexUpdateReq <= mid)  update(index*2, leftLimit, mid, indexUpdateReq, newValue);
	if (indexUpdateReq > mid)  update(index*2 + 1, mid + 1, rightLimit, indexUpdateReq, newValue);

	tree[index].sum = tree[index*2].sum + tree[index*2 + 1].sum;
	tree[index].maxRSum = max3(tree[index*2].maxRSum , tree[index*2].rightVal + tree[index*2 + 1].leftVal, tree[index*2 + 1].maxRSum);
	tree[index].leftVal = max2(tree[index*2].leftVal, tree[index*2].sum + tree[index*2 + 1].leftVal);
	tree[index].rightVal = max2(tree[index*2].rightVal + tree[index*2 + 1].sum, tree[index*2 + 1].rightVal);
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
	int x, y;
	int cntQuery;

	S(n);
	F(i,0,n)
		S(arr[i]);

	init(1, 0, n-1);
	// printTree(n);
	S(cntQuery);
	while(cntQuery--) {
		bool updateValue;

		//S(updateValue);
		updateValue = false;
		S(x), S(y);
		if (updateValue == false) {
			Tree result = query(1, 0, n-1, x-1, y-1);
			P(result.maxRSum),Ps("\n");
		} else {
			update(1,0,n-1, x-1, y);
		}
	}
	return 0;
}
