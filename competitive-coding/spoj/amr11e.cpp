#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;
int main()
{
	int i, j;
	int t,n,m,l,g;
	int prime[640];
	int arr[100000];
	int size;
	int tmp;
	int start;
	int flag;
      int k, ctr;
      map < int, int> mp;
      map < int, int> :: iterator it;
	size = 0;
	prime[size++] = 2;

	for( i = 3; i <= 2664; i++) {
		int flagp = 1;
		tmp = sqrt(i);
		for( j = 0; j < size; j++) {
			if(prime[j] > tmp) break;
			if(i%prime[j] == 0) {
				flagp = 0;
			}
		}
		if(flagp == 1) {
			prime[size++] = i;
		}
	}

      //for(i = 0; i<size; i++) printf("%d\n", prime[i]);
      ctr = 0;
      for( n = 30; n <= 3000 ; n++) {
      //flag = 0;
    	for( i = 0; i < size; i++) {
            if(n%prime[i] == 0)
            for( j = i+1; j < size; j++) {
                  if(n%prime[j] == 0)
                  for( k = j+1; k < size; k++) {
                        if( n%prime[k] == 0) {
                              mp.insert(pair <int, int> (n,1));
                             // printf("%d %d %d %d\n", prime[i],prime[j],prime[k],n);
                  }}
            }
      }
      }
      //printf("%d", mp.size());
	scanf("%d", &t);
	while(t--) {
            g = 0;
            scanf("%d", &l);
          for( it = mp.begin(); g < l; it++) {
                  g++;
                  if(l-g==0) printf("%d\n", it->first);
            }
/*
            scanf("%d", &n);
            printf("%d\n", arr[n]);
*/

      }
	return 0;
}

