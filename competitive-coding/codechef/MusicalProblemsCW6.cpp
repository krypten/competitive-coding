/*->>FireHash<<- Shubham Yadav*/
//Question Link Goes Here:
#include<bits/stdc++.h>
#include<climits>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb(x) push_back(x)
#define mp make_pair
#define fi(i, a, n) for(int i = (a); i < (n); ++i)
#define fx(i, a, n) for(int i = (a); i <= (n); ++i)
#define loop(i, a, n) for(i = (a); i < (n); ++i)
#define fd(i, a, n) for(int i = (a); i >= (n); --i)
#define fii(it, x) for(it = x.begin(); it != x.end(); ++it)
#define fid(it, x) for(it = x.end() - 1; it != x.begin() - 1; --it)//doesnot work on sets
#define vec(x) vector<x>
#define in(x) scanf("%d", &x)
#define inl(x) scanf("%lld", &x)
#define out(x) printf("%d\n", x)
#define outl(x) printf("%lld\n", x)
#define outs(x) printf("%s\n", x)
#define ins(x) scanf("%s", x)
#define fil(x,i) memset(x, i, sizeof(x))
//for debugging.. :)
#define dbl(i, sz, x) fi(i, 0, sz){cout<<x[i]<<" ";}cout<<endl
#define dbs(x) cout << x << endl
//general utilities.
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
ll ABS(ll a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second
const int INF = 0x3f3f3f3f;

/* Relevant code begins here */

/* Input from file or online */

void input() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}
/*  Input opener ends */
map <string, int> mymap;
vector<string> A(3);
int main()
{
        mymap["C"] = 0;
        mymap["c"] = 1;
        mymap["D"] = 2;
        mymap["d"] = 3;
        mymap["E"] = 4;
        mymap["F"] = 5;
        mymap["f"] = 6;
        mymap["G"] = 7;
        mymap["g"] = 8;
        mymap["A"] = 9;
        mymap["B"] = 10;
        mymap["S"] = 11;
        int t;
        in(t);
        while(t --){
                cin >> A[0] >> A[1] >> A[2];
                if(mymap[A[1]] > mymap[A[0]])
                        if(mymap[A[1]] - mymap[A[0]] == 3){
                                cout << "Minor\n";
                        } else {
                                cout << "Major\n";
                        }
                else
                        if(12 + mymap[A[1]] - mymap[A[0]] == 3){
                                cout << "Minor\n";
                        } else {
                                cout << "Major\n";
                        }
        }
        return 0;
}
