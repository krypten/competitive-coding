#include <stdio.h>
int main()
{   int t;
    int i;
    char ch;
    int sum;
    int array[60] = { 0 };
    
    
    scanf("%d\n",&t);
    
    while(t--) {
	
	
	sum = 0;
	for(i = 0; i < 60; i++) {
		array[i] = 0;	
	}
	
   	 scanf("%c",&ch);

   	while(ch != '\0' && ch != '\n') {
	        array[((int)ch)-64]++;
	        scanf("%c",&ch);
    	}
	
    	for(i = 0; i < 60; i++ ){
        	sum += array[i]/2 + array[i]%2 ;
    	}

    	printf("%d\n", sum);
    }
    return 0;
}
/*  while(ch=getc()) {
            if(ch == '0')
                break;
            printf("%c",ch);
        }
*/
