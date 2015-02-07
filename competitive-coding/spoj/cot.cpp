/*
 *  Author		: Krypten
 *  Algorithm	: Persistent Data Structure
 */

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
const int SIZE = 100000;
const int D = 21;


struct Node {
	static int MAX;

	int count;
	Node *left, *right;

	Node(int count, Node* left, Node* right): 
		count(count), left(left), right(right) {}

	Node* insert(int k);
	Node* insert(int l, int r, int k);
};

Node *null = new Node(0, NULL, NULL);

Node* Node::insert(int k) {
	return this->insert(0, MAX, k);
}

Node* Node::insert(int l, int r, int k) {
	if (l <= k && k < r) {
		if (l + 1 == r) {
			return new Node(this->count + 1, null, null);
		}
		int m = (l + r) >> 1;
		return new Node(this->count + 1, 
						this->left->insert(l, m, k),
						this->right->insert(m, r, k));
	}
	return this;
}

int n, m, weight[SIZE], edgeCount, firstEdge[SIZE], to[SIZE << 1], nextEdge[SIZE << 1];
int depth[SIZE], go[SIZE][D];
Node* root[SIZE];
int Node::MAX;

void addEdge(int u, int v) {
	to[edgeCount] = v;
	nextEdge[edgeCount] = firstEdge[u];
	firstEdge[u] = edgeCount++;
}

void dfs(int p, int u, Node* r) {
	depth[u] = p == -1 ? 0:depth[p] + 1;
	go[u][0] = p;
	for (int i = 0; i < D && go[u][i] != -1; ++i) {
		go[u][i + 1] = go[go[u][i]][i];				// store the path
	}
	root[u] = r->insert(weight[u]);
	for (int iter = firstEdge[u]; iter != -1; iter = nextEdge[iter]) {
		if (to[iter] != p) {
			dfs(u, to[iter], root[u]);
		}
	}
}

int jump(int u, int d) {
	F(i, 0, D) {
		if (d >> i & 1) {
			u = go[u][i];
		}
	}
	return u;
}

int lca(int u, int v) {
	if (depth[u] > depth[v]) {
		return lca(v, u);
	}
	// getting u and v at same depth
	v = jump(v, depth[v] - depth[u]);
	// if u and v are in same subtree
	if (u == v) {
		return u;
	}
	// running upwards till u and v meet
	for (int i = D - 1; i >= 0; --i) {
		if (go[u][i] != go[v][i]) {
			u = go[u][i];
			v = go[v][i];
		}
	}
	return go[u][0];
}

int query(Node *x, Node *y, Node *z, int l, int r, int k, int extra) {
	if (l + 1 == r) {
		return l;
	}
	int m = (l + r) >> 1;
	int count = x->left->count + y->left->count - 2* z->left->count;

	if (l <= extra && extra < m) {
		count++;
	}
	if (count >= k) {
		return query(x->left, y->left, z->left, l, m ,k, extra);
	}
	return query(x->right, y->right, z->right, m, r, k - count, extra);
}

int main() {
	input();
	null->left = null->right = null;
	
	S(n),S(m);
	V(int) values;
	F(i, 0, n) {
		scanf("%d", weight + i);
		values.pb(weight[i]);
	}
	// compressing values to index
	sort(values.begin(), values.end());
	values.erase(unique(values.begin(),values.end()), values.end());
	F(i, 0, n) {
		weight[i] = lower_bound(values.begin(), values.end(), weight[i]) - values.begin();
	}

	Node::MAX = values.size();
	edgeCount = 0;
	M(firstEdge, -1);
	F(i ,0 , n-1) {
		int a,b;
		S(a),S(b);
		--a; --b;
		addEdge(a,b);
		addEdge(b,a);
	}
	M(go, -1);
	dfs(-1, 0, null);
	while (m > 0) {
		--m;
		int a, b, k;
		S(a), S(b), S(k);
		--a; --b;
		int c = lca(a,b);

		P(values[query(root[a], root[b], root[c], 0, Node::MAX, k, weight[c])]), Ps("\n");
	}
	return 0;
}


