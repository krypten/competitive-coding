
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	void swap (long long int * , long long int , long long int);
	void quicksort (long long int *, long long int, long long int);
	long long int partition (long long int * , long long int, long long int);

      long long int binary_search (long long int * ptr, long long int beg,long long int end, long long int num )
	{
		long long int mid ;

		mid = (beg + end) / 2;

		while (beg < end)
		{
			if (ptr[mid] == num) {
				return 1;
		 	} else if (ptr[mid] > num) {
				end = mid ;
			} else if (ptr[mid] < num) {
				beg = mid + 1;
			}
			mid = (beg + end) / 2;

		}
		return -1;
	}
	int main ()
	{
		long long int i;
		long long int n;
            long long int k;
            long long int sum;
            long long int  * arrays ;

            sum = 0;

            scanf("%lld %lld", &n, &k);
            arrays = (long long int*) malloc((n+1) * sizeof(long long int));

		for(i = 0; i < n; i++)
		{
			scanf("%lld", &arrays[i] );
		}

		quicksort(arrays, 0, (n - 1));

		for(i = 0; i < n-1; i++)
		{
			if(binary_search(arrays, 0, n, (arrays[i] + k)) == 1)
                        sum++;
		}

		printf("%lld\n", sum);
		return 0;

	}

	void swap (long long int * ptr , long long int position1 , long long int position2)
	{
		long long int tmp;

		tmp = ptr [position1];
		ptr [position1] = ptr [position2];
		ptr [position2] = tmp;

	}


	void quicksort (long long int * ptr, long long int beg, long long int end)
	{
		long long int pivot_index;

		if (beg < end) {

			pivot_index = partition(ptr, beg, end);
			quicksort(ptr , beg , pivot_index - 1);
			quicksort(ptr , pivot_index + 1, end) ;
		}

	}

	long long int partition (long long int * ptr, long long int beg, long long int end)
	{

		long long int pivot_index;
		long long int i;
		long long int j;

		pivot_index = (rand() % (end - beg)) + beg;

//      pivot_index = end;

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
