/*->>FireHash<<- Shubham Yadav*/
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

int t, n, m;

#define SIZE 256
int a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE];
void calcBC(){
        fi(k, 0, m)
                fi(j, 0, n){
                        for(int i = 0; i + k < m && i + j < n; i ++){
                                b[k][j] += a[i + k][i + j];
                        }
                }
        fi(k, 0, m)
                fd(j, n - 1, 0){
                        for(int i = 0; i + k < m && j - i >= 0; i ++){
                                c[k][j] += a[i + k][j - i];
                        }
                }

        int mx = -200000001, ans;
        int lim = min(n, m);
        fi(k, 1, lim)
                for(int i = 0; i < m - k; i++){
                       for(int j = 0; j < n - k; j++){
                                if(k % 2 == 0){
                                        ans = b[i][j] + c[i][j + k]  - a[i + (k/2)][j + (k/2)];
                                        if(i + k + 1 < m && j + k + 1 < n){
                                                ans = ans - b[i + k + 1][j + k + 1];
                                        }
                                        if(i + k + 1 < m && j  - 1 >= 0){
                                                ans = ans - c[i + k + 1][j - 1];
                                        }
                                } else {
                                        ans = b[i][j] + c[i][j + k];
                                        if(i + k + 1 < m && j + k + 1 < n){
                                                ans = ans - b[i + k + 1][j + k + 1];
                                        }
                                        if(i + k + 1 < m && j - 1 >= 0){
                                                ans = ans - c[i + k + 1][j - 1];
                                        }
                                }
                                //cout << ans << endl;
                                if(ans > mx)
                                        mx = ans;
                        }
                }
        cout << mx << endl;
        /*fi(i, 0, m){
                fi(j, 0, n){
                        cout << b[i][j] << " ";
                }
                cout << "\n";
        }
        fi(i, 0, m){
                fi(j, 0, n){
                        cout << c[i][j] << " ";
                }
                cout << "\n";
        }cout << "\n";*/
}
int main()
{
        in(t);
        while(t --){
                fil(a, 0);
                fil(b, 0);
                 fil(c, 0);
                in(m); in(n);
                fi(i, 0, m){
                        fi(j, 0, n){
                                in(a[i][j]);
                        }
                }
                calcBC();

        }
        return 0;
}

