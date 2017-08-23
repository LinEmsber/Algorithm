/* Quick sort */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define XOR_SWAP(a, b) ( &(a) == &(b) ) ? (a) : ( (a) ^= (b), (b) ^= (a), (a) ^= (b) )

/* A safe free function.  */
void _safe_free(void **pp)
{
	if (pp != NULL && *pp != NULL){
		free(*pp);
		*pp = NULL;
	}
}
#define safe_free(p) _safe_free( (void**) &p )


/* A random number generator with integer data tyep and in a specific range.
 *
 * @len: The length of array.
 * @max: The max value of array.
 * @min: The min value of array.
 */
int * rand_num_generator_int( int len , int max, int min)
{
	int i;
	int * ret_arr = NULL;
	int range = max - min;

	// memroy allocation
	ret_arr = (int *) malloc( len * sizeof(int) );
	memset(ret_arr, 0, len + 1);

	// rand seed use time
	srand( (unsigned) time(NULL) );

	// generate arr
	for ( i = 0; i < len; i++ )
		*(ret_arr + i) = (rand() % range) + min;

	return ret_arr;
}


/* print the array with specific lenght
 *
 * @arr: the target array
 * @len: the length of array
 */
void print_arr(int *arr, int len)
{
	int i;

	for ( i = 0; i < len; i++)
		printf("%d ", *(arr + i) );

	printf("\n");
}

void quick_sort(int arr[], int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;

		if (i <= j) {
			// tmp = arr[i];
			// arr[i] = arr[j];
			// arr[j] = tmp;
			XOR_SWAP(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	/* recursion */
	if (left < j)
		quick_sort(arr, left, j);
	if (i < right)
		quick_sort(arr, i, right);
}


int main(int argc, char * argv[])
{
	int n =  atoi(argv[1]);

	int * arr = rand_num_generator_int( n, 255, 0 );

	printf("Original: \n");
	//	print_arr( arr, n );

	quick_sort(arr, 0, n-1);

	printf("After quick sort: \n");
	//	print_arr( arr, n );

	safe_free(arr);

	return 0;
}

