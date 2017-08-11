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
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}

		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
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
	int arr[] = {10, 2, 4, 5, 22, 898, 84, 12, 103, 331, 56};

	array_len = sizeof(arr) / sizeof(arr[0]);

        /* Before. */
        printf("Origin: \n");
	for(i = 0; i < array_len; i++)
		printf("%d ",arr[i]);
	printf("\n");

        /* Merge sort. */
	merge_sort(arr, 0, array_len);

        /* After. */
        printf("Merge sort: \n");
	for(i = 0; i < array_len; i++)
		printf("%d ",arr[i]);
	printf("\n");

	return 0;
}
