#include <cstdio>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{

	int t;
	int m, n, i;
	string key;
      map <string, int> mapi;
      map <string, int> :: iterator its;
      while(1) {
            int array[20020] = {0};
            scanf("%d %d", &n, &m);
            if ( n == 0 && m == 0) {
                  break;
            }

		for (i = 0; i < n; i++) {
			cin>>key;
			its = mapi.find(key);
			if (its == mapi.end()) {

				mapi.insert(pair <string, int> (key , 1));
			} else {
				its->second =its->second + 1;
			}
		}

            for ( its = mapi.begin(); its != mapi.end(); its++) {
                  array[its->second]++;
            }



            for (i = 1; i <= n; i++) {
                  printf("%d\n", array[i]);
            }
		mapi.clear();
      }
	return 0;
}
