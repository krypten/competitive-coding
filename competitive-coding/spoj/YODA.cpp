#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define LSOne(i) (i&-i)
int ft[32000];
using namespace std;

int rsq(int idx) {
      int sum =0; for(;idx; idx -= LSOne(idx)) sum += ft[idx];
      return sum;
}

void adjust(int k, int v) {
      for (;k<32000;k+=LSOne(k)) ft[k] += v;
}

int main()
{
      int t,i,n;
      string str;
      map <string, vector <int> > m;
      map <string, vector <int> > :: iterator it;
      vector <string> a;
      vector <int> v;
      int arr[32000];
      int arr2[32000];
      int sum;

      scanf("%d", &t);
      while(t--) {

            memset(ft , 0 , sizeof(ft));

            scanf("%d", &n);

            for (i = 0; i < n; i++) {
                  cin >> str;
                  v.push_back(i+1);
                  v.push_back(0);
                  m.insert(pair<string , vector <int> > (str, v));
                  v.clear();
            }

            for (i = 0; i < n; i++) {
                  cin >> str;
                  a.push_back(str);
            }

            for(i = 0; i < n; i++) {
                  it = m.find(a[i]);
                  it->second[1] = i+1;
//                  printf("%d %d\t", i+1, it->second[1]);
            }

            for(it = m.begin(); it != m.end(); it++) {
                  arr2[it->second[0]] = it->second[1];
            }

            sum = 0;
            for ( i = n; i >= 1; i--) {
                  sum = sum + rsq(arr2[i] - 1);
                  adjust(arr2[i], 1);
            }

            printf("%d\n", sum);

            m.clear();
            a.clear();
      }
      return 0;
}
