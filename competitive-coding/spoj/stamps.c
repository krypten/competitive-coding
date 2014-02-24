#include <stdio.h>

#define MAX 1005

void swap (int * , int , int);
void quicksort (int *, int, int);
int partition (int * , int, int);

int main (int argc, char **argv)
{
	int i;
	int j;
	int ctr;
	int tc;
	long long int sum;
	long long int target;
	int arr[MAX]; 

	scanf ("%d", &tc);
	for (i = 0; i<tc; i++)
	{
		sum = 0;		
		scanf ("%lld %d", &target, &ctr);
	
		for (j = 0; j < ctr; j++)
		{	
			scanf ("%d", &arr[j]);
			sum = sum + arr[j];
		}

		printf("Scenario #%d:\n", i + 1);

		if (target > sum) {
			printf ("impossible\n");
			continue;
		} else if (target == sum) {
			printf ("%d\n", ctr);
			continue;
		}

		quicksort(&arr[0],0, ctr - 1);

		sum = 0;
		
		for (j = ctr-1; j >= 0; j--)
		{		
			if(sum >= target) {
				break;		
			}
			sum = sum + arr[j];
		}
		printf("%d\n",ctr-1-j);
	}

	return 0;
}

void swap (int * ptr , int position1 , int position2)
{
	int tmp;

	tmp = ptr [position1];
	ptr [position1] = ptr [position2];
	ptr [position2] = tmp;
}

void quicksort (int * ptr, int beg, int end)
{
	int pivot_index;
	if (beg < end) {
		pivot_index = partition(ptr, beg, end);
		quicksort(ptr , beg , pivot_index - 1);
		quicksort(ptr , pivot_index + 1, end) ;
	}
}

int partition (int * ptr, int beg, int end)
{

	int pivot_index;
	int i;
	int j;

	pivot_index = (rand() % (end - beg)) + beg;
	swap(ptr, pivot_index, end);
	i = beg;
	j = beg;

	for (i = beg; i < end ; i++)
	{
		if (ptr[i] < ptr[end]) {
			swap(ptr, i, j);
			j = j + 1;
		}
	}

	swap (ptr, j, end);
	return j;
}
