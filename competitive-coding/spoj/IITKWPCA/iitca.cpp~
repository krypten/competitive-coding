#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;
typedef map<string,int> mii;

int main()
{
	int t;
	char str[10024];
	string tmp;
	mii m;

	scanf("%d", &t);
	while(t--) {
		m.clear();
		
		char * p;
		char c;
        	int j = 0,i;
		scanf("%c",&c);
        	scanf("%[^\n]s", str);
        	p = strtok (str," ");
        	while (p != NULL)
        	{
        	    string tmp(p);
			m.insert(pair<string, int> (tmp, 0));
        	    p = strtok (NULL, " ");
        	}		

		printf("%d\n", (int)m.size());				
	}

	return 0;

}
