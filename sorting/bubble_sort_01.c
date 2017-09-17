#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void bubble_sort(int * arr, size_t n)
{
	int i, j;
	for (i = 0; i < n - 1; i++){
		for(j = 0; j < n - i - 1; j++){

			if ( arr[j] > arr[j+1] )
				swap(&arr[j], &arr[j+1]);
		}
	}

}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/sizeof(arr[0]);

	printf("Original array: \n");
	printArray(arr, n);
	
	bubble_sort(arr, n);

	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
