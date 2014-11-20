/*
 *  Author		: Krypten
 *  Algorithm	: Balanced Binary Tree
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
#define mp make_pair
#define F(i,a,n) 	for(int i=(a);i<(n);++i)
#define FI(i,a,n) 	for(i=(a);i<(n);++i)
#define FD(i,a,n) 	for(int i=(a);i>=(n);--i)
#define FE(it,x) 	for(it=x.begin();it!=x.end();++it)
#define V(x) 		vector<x>
#define S(x) 		scanf("%d",&x)
#define Sl(x) 		scanf("%lld",&x)
#define Ss(x)		scanf("%s", x)
#define P(x) 		printf("%d",x)
#define Pl(x) 		printf("%lld",x)
#define Ps(x)		printf("%s", x)
#define M(x,i) 		memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) 	((a)>(b)?(a):(b))
#define MIN(a,b) 	((a)>(b)?(b):(a))
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
const int MAX_QUERY  = 200005;
#define INVALID_VALUE (INF + 1)

struct node {
	node * left;
	node * right;
	int aux;
	int key;
	int cnt;
	int size;
};

typedef node * Treap;
Treap t;
Treap nilTreap;
// memory management
node mem[MAX_QUERY];
vector<Treap> memStack;
int nodeCnt = 0;

void printT(Treap &root, int cnt);
inline void renewNode(Treap &root) {
	root->size = root->left->size + root->right->size + root->cnt;
}
inline void rotateLeft(Treap &root) {
	Treap tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	renewNode(root);
	root = tmp;
	renewNode(tmp);
}
inline void rotateRight(Treap &root) {
	Treap tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	renewNode(root);
	root = tmp;
	renewNode(tmp);
}

inline Treap getNode() {
	Treap node;
	if (memStack.size()) {
		node = memStack.back();
		memStack.pop_back();
	} else {
		if (nodeCnt > MAX_QUERY) return nilTreap;
		node = &mem[nodeCnt++];
	}
	return node;
}
inline void insertNode(Treap &root, int key) {
	if (root == nilTreap) {
		root = getNode();
		root->left = nilTreap;
		root->right = nilTreap;
		root->aux = rand() % INF;
		root->cnt = 1;
		root->size = 1;
		root->key = key;
		return;
	}
	if (root->key == key) return;
	else if (key < root->key) {
		insertNode(root->left, key);
		if (root->left->aux < root->aux)
			rotateLeft(root);
	} else {
		insertNode(root->right, key);
		if (root->right->aux < root->aux)
			rotateRight(root);
	}
	renewNode(root);
}
inline void deleteNode(Treap &root, int key) {
	if (root == nilTreap) return;
	if (root->key == key) {
		if ((root->left == nilTreap) && (root->right == nilTreap)) {
			memStack.push_back(root);
			root = nilTreap;
			return;
		} else {
			if (root->left->aux < root->right->aux) {
				rotateLeft(root);
				deleteNode(root->right, key);
			} else {
				rotateRight(root);
				deleteNode(root->left, key);
			}
		}
	} else if (key < root->key) {
		deleteNode(root->left, key);
	} else {
		deleteNode(root->right, key);
	}
	renewNode(root);
}
inline int getRank(Treap &root, int x) {
	if (root == nilTreap) return 0;
	if (x < root->key) return getRank(root->left, x);
	else if (x == root->key) return root->left->size + getRank(root->right, x);
	else return root->left->size + root->cnt + getRank(root->right, x);
}
inline int getKthSmaller(Treap &root, int k) {
	if (root == nilTreap) return INVALID_VALUE;
	if (k == root->left->size + root->cnt) return root->key;
	if (k > root->size) {
		return INVALID_VALUE;
	}
	else {
		if (k <= root->left->size) {
			return getKthSmaller(root->left, k);
		} else {
			return getKthSmaller(root->right, k - root->left->size - root->cnt);
		}
	}
}
void printT(Treap &root, int cnt) {
	if (root == nilTreap) {
//printf("#(%d) ", cnt);
		return;
	}
	printf("%d-%d-%d(%d) ", root->key, root->size, root->cnt, cnt);
	printT(root->left, cnt+1);
	printT(root->right, cnt+1);
}
void printInorder(Treap &root, int cnt) {
	if (root == nilTreap) {
//printf("#(%d) ", cnt);
		return;
	}
	printInorder(root->left, cnt+1);
	printf("%d(%d) ", root->key, cnt);
	printInorder(root->right, cnt+1);
}
inline void initTree() {
	nilTreap = new node();
	nilTreap->left = nilTreap;
	nilTreap->right = nilTreap;
	nilTreap->aux = INF;
	nilTreap->size = 0;
	nilTreap->cnt = 0;
// TODO
	nilTreap->key = INVALID_VALUE;
}

int main() {
	input();
	int n;
	int query;

	initTree();
	t = nilTreap;
	S(query);
	while (query--) {
		char op[32];
		scanf("%s %d", op, &n);
		if (!strcmp(op, "I"))
			insertNode(t, n);
		else if (!strcmp(op, "D"))
			deleteNode(t, n);
		else if (!strcmp(op, "K")) {
			int x = getKthSmaller(t, n);
			if (x == INVALID_VALUE)
                Ps("invalid\n");
            else
                printf("%d\n", x);
        } else if (!strcmp(op, "C")) {
				int x = getRank(t, n);
			if (x == INVALID_VALUE)
                Ps("invalid\n");
            else
                printf("%d\n", x);
		}
	}
	return 0;
}
