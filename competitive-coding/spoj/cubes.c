#include <stdio.h>
#include <math.h>

int main()
{
	int i, j, k;
	double sum, tmp;
	int temp1, temp2,temp3,tmp3;
	int a[128][4] = {0};
	int ctr = 0;

	for ( i  = 2; i < 64 ; i++) {
		for( j = i; j < 80 ; j++ ) {	
			for ( k = j; k < 100; k++) {
				sum = i*i*i + j*j*j + k*k*k;
				tmp = cbrt( sum );
				if (tmp - floor(tmp) < 0.000000001) {
					a[ctr][0] = tmp; a[ctr][1] = i;a[ctr][2] = j;a[ctr][3] = k;
					ctr++; 				
				}
			}
		}
	}

	for(i=0;i<ctr -1;i++)
	{
    		for (j=0;j<ctr-1-i;j++)
    		{
        	if(a[j][0]>a[j+1][0])
        	{
            	temp1=a[j][0];
            	temp2=a[j][1];
    	        temp3=a[j][2];
		tmp3=a[j][3];
    	        a[j][0]=a[j+1][0];
    	        a[j][1]=a[j+1][1];
    	        a[j][2]=a[j+1][2];
    	        a[j][3]=a[j+1][3];
    	        a[j+1][0]=temp1;
    	        a[j+1][1]=temp2;
    	        a[j+1][2]=temp3;
    	        a[j+1][3]=tmp3;
        	}
    		}
	}

	for ( i = 0; i < ctr ; i++) {
		if (a[i][0] > 100) break;
		printf("Cube = %d, Triple = (%d,%d,%d)\n",a[i][0], a[i][1], a[i][2], a[i][3]);
	}

	return 0;
} 
