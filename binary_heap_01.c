/* The implementation of binary heap in C. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void swap(int * a, int * b);

int * build_max_heap(int arr[], int n);
void max_heapify(int arr[], int i, int heap_size);

int * build_min_heap(int arr[], int n);
void min_heapify(int arr[], int i, int heap_size);


void swap(int * a, int * b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


int * build_max_heap(int arr[], int n)
{
	int i;
	int heap_size = n;

	for (i = n / 2; i >= 0; i--)
		max_heapify(arr, i, heap_size);

	return arr;
}

void max_heapify(int arr[], int i, int heap_size)
{
	int largest = i;
	int left = ( ( 2 * i ) + 1 );
	int right = ( ( 2 * i ) + 2 );

	if (left >= heap_size)
		return;

	/* Compare the left child and the root to find the node which is the largest number. */
	if (left < heap_size && arr[left] > arr[i])
		largest = left;

	/* Compare the right child and the root to find the node which is the largest number. */
	if (right < heap_size && arr[right] > arr[largest])
		largest = right;

	/* If the root is not the largest number, swap the root wiht the child which is the largest number. */
	if (largest != i) {
		swap(&arr[i], &arr[largest]);

		/* It necessary to recursively heapify the corresponding subarrays after swap the two nodes. */
		max_heapify(arr, largest, heap_size);
	}
}


int * build_min_heap(int arr[], int n)
{
	int i;
	int heap_size = n;

	for (i = n / 2; i >= 0; i--)
		min_heapify(arr, i, heap_size);

	return arr;
}

void min_heapify(int arr[], int i, int heap_size)
{
	int smallest = i;
	int left = ( 2 * i + 1 );
	int right = ( ( 2 * i ) + 2 );

	if (left >= heap_size)
		return;

	/* Compare the left child and the root to find the node which is the smallest number. */
	if (left < heap_size && arr[left] < arr[i])
		smallest = left;

	/* Compare the right child and the root to find the node which is the smallest number. */
	if (right < heap_size && arr[right] < arr[smallest])
		smallest = right;

	/* If the root is not the smallest number, swap the root wiht the child which is the smallest number. */
	if (smallest != i) {
		swap(&arr[i], &arr[smallest]);

		/* It necessary to recursively heapify the corresponding subarrays after swap the two nodes. */
		min_heapify(arr, smallest, heap_size);
	}
}


int main()
{
	int i;
	int len = MAX;

	int * array_original = calloc(len, sizeof(int));
	int * array_max_heapify = calloc(len, sizeof(int));
	int * array_min_heapify = calloc(len, sizeof(int));

	/* Max heapifty. */
	for (i = 0; i < len; i++){
		*(array_original + i) = i + 1;
	}

	printf("The original array:\n");
	for (i = 0; i < len; i++)
		printf("%d ", array_original[i]);
	printf("\n");

	array_max_heapify = build_max_heap(array_original, len);

	printf("After the max heapfity:\n");
	for (i = 0; i < len; i++)
		printf("%d ", array_max_heapify[i]);
	printf("\n");

	/* Min heapifty. */
	for (i = 0; i < len; i++){
		*(array_original + i) = len - i;
	}

	printf("The original array:\n");
	for (i = 0; i < len; i++)
		printf("%d ", array_original[i]);
	printf("\n");

	array_min_heapify = build_min_heap(array_original, len);

	printf("After the min heapfity:\n");
	for (i = 0; i < len; i++)
		printf("%d ", array_min_heapify[i]);
	printf("\n");

	return 0;
}
