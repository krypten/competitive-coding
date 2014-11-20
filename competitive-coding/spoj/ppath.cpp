/*
 *  Author		: Krypten
 *  Algorithm	: Adhoc
 */

#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

#define INF INT_MAX/2
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

int start , end ;
bool p[10005],visit[10005] ;
int b[5] ;
struct Node
{
	int cur ;
	int level ;
};

bool isprime(int a)
{
	if(a % 2 == 0) return false ;
	else
	{
		for(int j = 3 ; j <= a / 2 ; j ++)
		{
			if( a % j == 0)
			{
				return false ;
			}
		}
		return true ;
	}
}
void prime_table()
{
	memset(p,0,sizeof(0)) ;
	for(int i = 1000 ; i <= 10000 ; i ++)
	{
		p[i] = isprime(i) ;
	}
}
void get_num ( Node node )
{
	b[1] = node.cur % 10 ;
	b[2] = ( node.cur % 100 ) / 10 ;
	b[3] = ( node.cur % 1000 ) / 100 ;
	b[4] = ( node.cur % 10000 ) / 1000 ;
}
int bfs()
{
	if(start == end) return 0 ;
	memset(visit,0,sizeof(visit)) ;
	visit[ start ] = 1 ;
	Node node ;
	node.cur = start ; node.level = 0 ;
	queue<Node> q ;
	q.push(node) ;
	while( 1 )
	{
		Node node_temp = q.front () ;
		q.pop () ;
		get_num ( node_temp ) ;
		for(int i = 1 ; i<= 4 ; i ++)
		{
			int c = node_temp.cur - b[i] * pow(10.0,i-1) ;
			for(int j = 0 ; j <= 9 ; j ++)
			{
				int new_c = c + j * pow(10.0,i-1) ;
				if(new_c == end) return node_temp.level + 1 ;
				if( new_c < 1000 || visit[new_c] == 1 || p[new_c] == 0 ) continue ;
				visit[new_c] = 1 ;
				Node node_new ;
				node_new.cur = new_c ;
				node_new.level = node_temp.level + 1 ;
				q.push (node_new) ;
			}
		}
	}
}

int main()
{
	input();
	int t;
	cin >> t ;
	prime_table() ;
	while(t--) {
		cin >> start >> end ;
		cout << bfs() << endl ;
	}
	return 0;
}