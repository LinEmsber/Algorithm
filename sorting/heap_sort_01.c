#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
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

/* Heap sort. */
void heap_sort(int arr[], int len, void (*heapify)(int arr[], int i, int heap_size))
{
	int i;

	/* Build binary heap (rearrange array). */
	for (i = len / 2 - 1; i >= 0; i--){
		heapify(arr, i, len);
	}

	printf("After building binary heap:\n");
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	for (i = len - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, 0, i);
	}
}


int main()
{
	int i;
	int array_original[] = {8, 2, 12, 15, 13, 5, 1, 7, 0};
	int len = sizeof(array_original) / sizeof(array_original[0]);

	/* From max to min. */
	printf("\nThe original array:\n");
	for (i = 0; i < len; i++)
		printf("%d ", array_original[i]);
	printf("\n");

	heap_sort(array_original, len, min_heapify);

	printf("After heap sort (from max to min):\n");
	for (i = 0; i < len; i++)
		printf("%d ", array_original[i]);
	printf("\n");
	printf("\n");

	/* From min to max. */
	printf("The original array:\n");
	for (i = 0; i < len; i++)
		printf("%d ", array_original[i]);
	printf("\n");

	heap_sort(array_original, len, max_heapify);

	printf("After heap sort (from min to max):\n");
	for (i = 0; i < len; i++)
		printf("%d ", array_original[i]);
	printf("\n");
	printf("\n");

	return 0;
}
