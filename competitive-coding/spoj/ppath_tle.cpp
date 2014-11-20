/*
 *  Author		: Krypten
 *  Algorithm	: Primes + BFS
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

#define HIGHER 10000
#define SIZE 1300
#define INDEX_LOWER 168
#define DIGIT 4

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

int primes[SIZE];
bool visited[SIZE];
int nodes[HIGHER];
bool matrix[SIZE][SIZE];

int cnt = 2;
void generatePrimes()
{
	primes[0] = 2; nodes[2] = 0;
	primes[1] = 3; nodes[3] = 1;
	F(i, 5, HIGHER) {
		bool flag = true;
		F(j, 0 , cnt) {
			if (i % primes[j] == 0) {
				flag = false;
			}
		}
		if (flag) {
			nodes[i] = cnt;
			primes[cnt++] = i;
		}
	}
	//cout << primes[INDEX_LOWER] << " " << cnt << endl;
}

void addEdge(int i, int j, int offset) {
	matrix[i-offset][j - offset] = true;
	matrix[j-offset][i - offset] = true;
}

bool valid(string s1, string s2)
{
	int cnt = 0;
	F(i,0,DIGIT)
		if (s1[i] != s2[i])
			cnt++;

	if (cnt == 1) {
		//cout << p1 << s1 << " " << p2 << s2 << endl;
		return true;
	}

	return false;
}

string getStr(int p1)
{
	string s1 = "";
	
	F(i,0,DIGIT) {
		s1 = char(p1%10 + '0') + s1; p1 = p1/10;
	}
	return s1;
}

int getNum(string s1)
{
	int p1 = 0;
	//cout << s1 << " \n\t" << (int)s1[0] <<endl;
	F(i,0,DIGIT) {
	//	cout << p1 << " ";
		p1 = p1*10 + (s1[i]-'0');
	}
	//cout <<" NUMBER " << p1 <<endl;
	return p1;
}

bool valid(int p1, int p2)
{
	string s1 = getStr(p1);
	string s2 = getStr(p2);

	return (valid(s1,s2));
}


void generateMatrix()
{
	F(i,INDEX_LOWER,cnt) {
		F(j,i+1,cnt) {
			if (valid(primes[i], primes[j]))
				addEdge(i,j,0);
		}
	}
}

int bfs(int source, int destination)
{
//	cout << source << " " << destination << endl;
	int num = 0;
	M(visited,0);
	queue <pii> q;
	q.push(pii(source, 0));
	while( !q.empty()) {
		pii i = q.front(); q.pop();

	//	cout << "\nProcessing : " << i.fr << " " << i.se << "\n";
		
		if(i.fr == destination)
			return i.se;
		if (visited[i.fr])
			continue;
		visited[i.fr] = true;
		
		string s = getStr(primes[i.fr]);
		F(u, 0, DIGIT) {
			F(v, 0, 10) {
				if (u == 0 && v == 0)
					continue;
				string temp = s;
				temp[u] = char(v+'0');
				num = getNum(temp);
	//			cout << temp << " \t"<< num << " " <<  nodes[num] << "\t" << matrix[i.fr][nodes[num]] << " " << visited[nodes[num]] << endl;
				if (temp != s && nodes[num] != 0 && (matrix[i.fr][nodes[num]]) && (!visited[nodes[num]])) {
	//				cout << "pushed @ " << num << " " << i.se + 1<<endl;
					q.push(pii(nodes[num], i.se + 1));
				}
			}
		}
		//F(j,0, cnt - INDEX_LOWER) {
		//	if ((i.fr != j) && (matrix[i.fr][j]) && !visited[j]) {
		//		cout << "pushed @ " << j << " " << i.se + 1<<endl;
		//		q.push(pii(j, i.se + 1));
		//	}
		//}
	}
	return -1;
}

int main()
{
	input();
	int t;
	int n, m;
	M(nodes,0);
	generatePrimes();
	M(matrix,0);
	generateMatrix();

	S(t);
	//t = 1;
	while (t--) {
		S(n), S(m);
	/*	F(i,0,HIGHER)
			if (nodes[i] != 0)
				cout<<i << " ";
		cout << endl;
	*/	
		int ans = bfs(nodes[n], nodes[m]);
		//Ps("answer : ");
		if (ans == -1)
			Ps("Impossible\n");
		else 
			P(ans),Ps("\n");
	}
	return 0;
}