/*
 *  Author		: Krypten
 *  Algorithm	: N Segment Trees
 */

#include <map>
#include <queue>
#include <vector>
#include <algorithm>
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
const int SIZE = 111111;

struct Node {
	int count;
	Node* left; Node* right;

	Node(int count, Node *_left, Node *_right) :
		count(count), left(_left), right(_right) {};

	Node* insert(int l, int r, int w);
};

Node *null = new Node (0, NULL, NULL);

Node* Node::insert(int l, int r, int k) {
	if (l <= k && k < r) {
		if (l+1 == r) {
			return new Node(this->count+1, null, null);
		}
		int m = (l + r) >> 1;
		return new Node(this-> count + 1,
						this->left->insert(l, m, k),
						this->right->insert(m, r, k));
	}
	return this;
}

int query(Node*x, Node *y, int l, int r, int k) {
	if (l+1 == r) {
		return l;
	}
	int m = (l + r) >> 1;
	int count = x->left->count - y->left->count;
	if (count >= k) {
		return query(x->left, y->left, l, m, k);
	}
	return query(x->right, y->right, m, r, k-count);
}

int arr[SIZE], RM[SIZE];
Node *root[SIZE];

int main() {
	input();

	int n, m;
	map<int, int> edgemap;
	S(n), S(m);


	null->left = null->right = null;

	F(i,0,n) {
		S(arr[i]);
		edgemap[arr[i]];
	}

	// compression to index values
	int maxi = 0;
	for(map <int, int> :: iterator it = edgemap.begin(); it != edgemap.end(); it++)
	{
		edgemap[it->first] = maxi;
		RM[maxi] = it->first;
		maxi++;
	}

	F(i,0,n) {
		// Build a tree for each prefix using segment tree of previous prefix
		root[i] = (i == 0 ? null: root[i-1])->insert(0, maxi, edgemap[arr[i]]);
	}

	while (m--) {
		int u, v, k;
		S(u), S(v), S(k);
		--u, --v;
		int ans = query(root[v], (u==0? null:root[u-1]), 0, maxi, k);
		P(RM[ans]),Ps("\n");
	}

	return 0;
}