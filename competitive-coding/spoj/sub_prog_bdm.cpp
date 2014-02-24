//algo : BDM ( backward dawg matching)
//stg -> state transition graph
//final -> final state graph in vector form
// sigma -> range if alphabet in automata
// jump -> jump back to previous accepted state

#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>

#define sigma 130
#define MAX 100010

using namespace std;

char T[MAX] ;
int stg[MAX][ 260 ] ;
vector<int> final[MAX] ;
int jump[MAX] ;	
bool enc[1010] ;
int end ;

void init() {
	end = 1;
}

void add(string s, int idx) {
	int len = s.size();
	int state = 0;
	for(int i = 0; i < len; i++) {
		int c = s[i];
		if( !stg[state][c] ) {
			stg[state][c] = end++;
		}
		state = stg[state][c];
	}

	final[state].push_back(idx);
}

void compute_transition_matrix() {
	queue<int> q;
	for(int i = 0; i < sigma; i++) {
		int next = stg[0][i];
		if ( next ) {
			jump[next] = 0;
			q.push(next);
		}
	}
	
	while( !q.empty()) {
		int state = q.front();
		q.pop();
		for (int i = 0; i < sigma; i++) {
			int next = stg[state][i];
			int rev = stg[jump[state]][i];
			if ( next == 0) 
				stg[state][i] = rev;
			else {
				q.push(next);
				jump[next] = rev;
				for(int j = 0; j < final[rev].size(); j++) {
					final[next].push_back(final[rev][j]);
				}
			}
		}
	}
}

void search() {
	int len = strlen(T);
	int state = 0;
	for (int i = 0; i < len; i++) {
		int c = T[i];
		while( state != 0 && stg[state][c] == 0) {
			state = jump[state];
		}
		state = stg [state][c];
		for (int j = 0; j < final[state].size(); j++) {
			enc[final[state][j]] = true;
		}
	}
}

int main()
{
	int n;
	char s[2013];

	scanf("%s", T);
	scanf("%d", &n);
	init();
	
	for(int i = 0; i < n; i++) {
		scanf("%s", s);
		add(s, i);
	}

	compute_transition_matrix();
	search();
	
	for(int i = 0; i < n; i++ ) {
		printf("%s\n", enc[i] ? "Y" : "N");
	}

	return 0;
}
