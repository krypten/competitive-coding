#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[200024];
char * p;


int main()
{
	int mini;
	int len;
	int i;
	int t;
	scanf("%d", &t);
	while(t--) {

	scanf("%s", str);
	
	len = strlen(str);
	p = (char*) malloc(sizeof(char) * (2*len  + 2));
	strcpy(p, str);
	strcat(p,str);
	
	mini = 0;
	for( i = 1; i < len; i++) {
//		for(ctr = 0; ctr < len; ctr++) {
//			if(str[mini + ctr] > str[i + ctr]) {
			if (strncmp(p+mini, p+i, len) > 0) {
			mini = i;}
//			else break;
//		}
	}
	printf("%d\n", mini + 1);
	}
	return 0;
}
