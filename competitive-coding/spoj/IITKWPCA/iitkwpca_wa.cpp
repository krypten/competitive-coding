#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;
typedef map<string,int> mii;

int main()
{
	int t;
	int i;
	int flag;
	int ctr;
	char c;
	mii m;
		
	char str[10024];
	char str1[10024];

	scanf("%d", &t);
	while(t--) {
		m.clear();
		char tmp[10024];
		scanf("%c", &c);
		scanf("%[^\n]s", str1);
		str[0] = ' ';
		str[1] = '\0';
		strcat(str, str1);
		strcat(str,"9");
		ctr = 0;

		flag = 1;
		for( i=0; str[i] != '9'; i++) {
			if(str[i] == ' ') {
				flag = 1;
			} else {
				if(flag == 1) {
					tmp[ctr] = '\0';
					string s(tmp);
					m.insert(pair<string , int> (s, 0));
					ctr = 0;
					tmp[ctr] =  str[i];
					ctr++;  
					flag = 0;
				} else {
					tmp[ctr] = str[i];
					ctr++;
				}
			}
		}
		string s(tmp);
		
		m.insert(pair <string, int> (s, 0));
		printf("%d\n", (int)m.size() -1);
								
	}

	return 0;

}
