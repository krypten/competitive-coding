#include <stdio.h>

#define MAX 101

int main ()
{
	int i;
	int j;
	int n;
      int tc;
      int c;
	int num;
	double p;
	int k;
	double tmp2;
	double f;
	double tmp;
      long long int y[MAX][MAX + 1] = {0};

      scanf("%d", &tc);

      while(tc--){
	scanf("%d %d", &n, &c);

	for ( i = 0; i < n; i++)
	{
		scanf("%d",&y[i][0]);
	}

	for(i = 1;i<n;i++)
	{
		for(j =0; j< n-i; j++)
		{
			y[j][i] = y[j+1][i-1]-y[j][i-1];
		}

	}

      for(j =0; j<c; j++) {
	num = n + j + 1;

      p = num - 1;

/*    p = (num-x[0])/(x[1]- x[0]);   */

	tmp = 1;
	tmp2 = 1;
	f = y[0][0];


	for(k = 1; k < i+1; k++) {
		tmp  = tmp * ((p--)/ tmp2++);
		f += tmp * y[0][k];
	}

	printf("%.0lf ",f);
      }
      printf("\n");
      }
	return 0;
}
