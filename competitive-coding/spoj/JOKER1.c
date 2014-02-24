	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#define MAX 1024


	void swap (int * , int , int);
	void quicksort (int *, int, int);
	int partition (int * , int, int);

	int main ()
	{
		int i;
		int size;
            int t;
            unsigned long long int j;
		int array [MAX];

            scanf("%d", &t);
            while (t--) {
		scanf("%d", &size);
            j = 1;
		for(i = 0; i < size; i++)
		{
			scanf("%d", &array[i] );
		}

		quicksort ( &array[0], 0, size - 1);

            for(i = 0; i < size; i++) {
                  j = (j*(array[i]-i)%1000000007);
                  if (j == 0)
                        break;
            }
            printf("%llu\n", j);
            }
            printf("KILL BATMAN\n");
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
