#include <stdio.h>
#include <string.h>

void permute (char * str, int ctr)
{
	int i;	
	int len;
	char tmp;

	len = strlen(str) ;
	tmp = str[0];

	for( i = 1; i < len ; i++)
	{
		str[i-1] = str[i];
	}
	
	str[len-1] = tmp;
}

void str_cat (char * str, int ctr)
{
	int i;	
	char tmp[505];

	strcpy(tmp, str);
	
	for( i = 0; i < ctr ; i++)
	{
		strcat(str, tmp);
	}
}

int main (int argc, char **argv)
{
	char str[505];	
	int i;
	int len;
	int ctr;
		
	while(1)
	{
		(void)scanf("%s", &str, &ctr);

		if(!(strcmp(str,"."))){
			break;
		}

		(void)scanf("%d", &ctr);
//		(void)printf("%s %d\n", str, ctr);

		len = strlen(str);
//		printf("%d\n", len);

		str_cat(str, ctr-1); 
//		(void)printf("%s %d\n", str, ctr);
	
		(void)printf("%s\n",str);

		for (i = 0; i < len-1; i++)
		{
			permute(str,ctr);
			(void)printf("%s\n", str);
		}
	}
return 0;

}

