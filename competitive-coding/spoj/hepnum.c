#include <stdio.h>
#include <string.h>

int main()
{
	int len1,i,j,len2,tmp,ans;
	
	while(1) {
		char str1[1000000] = {0};
		char str2[1000000] = {0};
		char fn1[1000000] = {0};
		char fn2[1000000] = {0};
		
		scanf("%s %s",str1, str2);
		
		if (str1[0] == '*') {
			break;
		}
		
		len1 = strlen(str1);
		len2 = strlen(str2);

		for( i = 0; (str1[i] == '0') && (i < len1); i++) ;
		for( j = 0; (str2[j] == '0') && (j < len2); j++) ;
		
		for ( tmp = 0; i < len1; tmp++,i++) {
			fn1[tmp] = str1[i];
		}
		//fn1[tmp] = '\0';
		//printf("%s\n", fn1);
		
		for ( tmp = 0; j < len2; tmp++,j++) {
			fn2[tmp] = str2[j];
		}
		//fn2[tmp] ='\0';
		//printf("%s\n", fn2);
		len1 = strlen(fn1);
		len2 = strlen(fn2);

		if (len1 > len2) {
			ans = 1;
		} else if ( len1 < len2) {
			ans = -1;
		} else {
			ans = strcmp(fn1,fn2);
		}
		if ( ans > 0) {
			printf(">\n");
		} else if (ans < 0) {
			printf("<\n");
		} else {
			printf("=\n");
		}
	}
	
	return 0;
}
