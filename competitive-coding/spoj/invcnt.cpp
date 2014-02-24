#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;
long long int ft[500020];
#define LSOne(S) (S & (-S))


  long long int rsq(int b) {                                     // returns RSQ(1, b)
    long long int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }

  // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
  void adjust(int k, int v) {                    // note: n = ft.size() - 1
    for (; k < (int)500020; k += LSOne(k)) ft[k] += v; }

int main()
{
      mii m;
      mii:: iterator it;
      int t;
      int n, i;
      int tmp;
      long long int sum;
      int arr[500020];

      scanf("%d", &t);
      while(t--) {
            scanf("%d", &n);
            memset(ft, 0, sizeof(ft));

            for ( i = 1; i <= n; i++) {
                  scanf("%d", &tmp);
                  m.insert(pair<int, int> (tmp, i));
                  //printf("Insertion OK\n");
                  //ft.adjust(tmp, 1);
                  //printf("%d\n", ft.rsq(tmp));
            }
            for ( it = m.begin(), i = 0; it != m.end(); it++) {
                  arr[i] = it->second;
                  i++;
                  //printf("%d\t", arr[i-1]);
            }

            sum = 0;
            for ( i = n-1; i >= 0; i--) {
                  sum = sum + rsq(arr[i] - 1);
                  adjust(arr[i], 1);
            }

            printf("%lld\n", sum);
            m.clear();
      }
      return 0;
}
