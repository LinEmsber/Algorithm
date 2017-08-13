/* Merge sort in C */

#include<stdio.h>
#include<stdlib.h>

/* Merges two subarrays of arr[].
 * The first subarray is arr[l..m] and the second subarray is arr[m+1..r].
 */
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	/* Merge the temp arrays back into arr[l..r].
         * i:Initial index of first subarray
         * j:Initial index of second subarray
         * k:Initial index of merged subarray
         */
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)  {
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
		arr[k++] = L[i++];

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
		arr[k++] = R[j++];
}

/* merge sort
 * l: the left index of the array to be sorted.
 * r: the right index of the array to be sorted.
 */
void merge_sort(int arr[], int l, int r)
{
	if (l < r)
	{
		/* Avoids overflow for large l and h. */
		int m = l + ( r - l ) / 2;

		/* Sort first and second halves. */
		merge_sort(arr, l, m);
		merge_sort(arr, m+1, r);

		merge(arr, l, m, r);
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
	merge_sort(arr, 0, array_len - 1);

        /* After. */
        printf("Merge sort: \n");
	for(i = 0; i < array_len; i++)
		printf("%d ",arr[i]);
	printf("\n");

	return 0;
}
