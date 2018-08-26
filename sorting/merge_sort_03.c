/* Merge sort in C */

#include<stdio.h>
#include<stdlib.h>

void merge_sort(int *, int);
void sort(int *, int *, int, int);
void merge(int *, int*, int, int, int);

/* Create a temp array to store the values of sorted data during time of sorting process */
void merge_sort(int arr[], int size)
{
	/* Create an auxilary array to store sorted data. */
	int *tmp = (int *)malloc(sizeof(int) * size);
	
	/* Call the function to sort data. */
	sort(arr, tmp, 0, size - 1);
}

/* It divides the problem into subproblems and solve them seperately. 
 * Finally, it combines the data of two subproblems by calling merge().
 */
void sort(int arr[], int tmp[], int start, int end)
{
	/* Divide into subproblems. */
	if (start < end) {
		int mid;
		// calculating the mid vaue
		mid = start + (end - start) / 2;

		//sorting part 1
		sort(arr, tmp, start, mid);

		//sorting part 2
		sort(arr, tmp, mid + 1, end);

		//combining the two sorted parts
		merge(arr, tmp, start, mid+1, end);
	}
}

/* It combines the two subproblems. 
 * It is the conquer part of divide and conquer algorithm.
 */
void merge(int arr[], int tmp[], int start, int mid, int end)
{
	int i, j, k;
	i = start;	/* The first subpart. */
	j = mid;	/* The second subpart. */
	k = start;	/* The temporary array. */

	/* runs till one of the subarray gets the last element. */
	while ((i < mid) && (j <= end)) {
		if (arr[i] <= arr[j]) {
			tmp[k++] = arr[i++];
		} else {
			tmp[k++] = arr[j++];
		}
	}

	/* If j was the last element, j > end, elements are still left in the first subpart. */
	while (i < mid) {
		tmp[k++] = arr[i++];
	}

	/* If i was the last element, i == mid, elements are still left in the second subpart. */
	while (j <= end) {
		tmp[k++] = arr[j++];
	}

	/* Copy back. */
	for (i = start; i <= end; i++) {
		arr[i] = tmp[i];
	}
}

int main()
{
        int i;
        int array_len;
        int arr[] = {10, 2, 4, 5, 22, 98, 84, 12, 13, 31, 56,
			310, 302, 604, 505, 322, 388, 684, 312, 613, 331, 656,
			412, 208, 302, 302, 482, 378, 482, 318, 412, 238, 252,
			212, 102, 602, 284, 372, 128, 672, 284, 212, 131, 152,
			412, 408, 182, 375, 422, 498, 122, 372, 182, 432, 652,
			314, 384, 674, 523, 324, 394, 684, 323, 474, 388, 354,
			483, 378, 323, 305, 423, 298, 383, 312, 323, 371, 683,
			373, 123, 603, 205, 623, 193, 683, 212, 413, 128, 673,
			420, 408, 404, 108, 422, 498, 184, 112, 413, 438, 426};

        array_len = sizeof(arr) / sizeof(arr[0]);

        /* Before. */
        printf("Origin: \n");
	for(i = 0; i < array_len; i++)
		printf("%d ",arr[i]);
	printf("\n");

        /* Merge sort. */
	merge_sort(arr, array_len);

        /* After. */
        printf("Merge sort: \n");
	for(i = 0; i < array_len; i++)
		printf("%d ",arr[i]);
	printf("\n");

	return 0;
}
