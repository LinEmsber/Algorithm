

/* Merge sort in C */

#include<stdio.h>
#include<stdlib.h>

/* merge arrays L and R into arr.
 * @lefCount: number of elements in L
 * @right_length: number of elements in R.
 */
void merge_array(int * arr, int * L, int left_length, int * R, int right_length)
{
        /* i: the index of left aubarray, L
         * j: the index of right sub-raay, R
         * k: the index of merged subarray, arr
         */
        int i = 0, j = 0, k = 0;

        /* Compare the two sub array and fill the larger element into the array, until
         * one of array's elements are filled out.
         */
         while(i < left_length && j < right_length) {
                 // if( L[i] < R[j] )
                 //         arr[k++] = L[i++];
                 // else
                 //         arr[k++] = R[j++];
                 int v1 = L[i];
                 int v2 = R[j];
                 int take = v1 < v2;
                 arr[k++] = take ? v1 : v2;
                 i += take;
                 j += 1-take;
         }

        /* Fill the remaining elements out. */
        while(i < left_length)
                arr[ k++ ] = L[ i++ ];

        while(j < right_length)
                arr[ k++ ] = R[ j++ ];
}

/* Recursive function to sort an array of integers.
 * @arr: integer array
 * @len: length of array
 */
void merge_sort(int * arr, int len)
{
        int i;
        int mid, * L, * R;

        /* If the array has less than two element, do nothing. */
        if(len < 2)
                return;

        /* Find the mid index. ( even number / 2 = (even number - 1) / 2 ) */
        mid = len / 2;

        /* Create left and right subarrays
         * left sub-array: mid elements, from index 0 till mid-1
         * right sub-array: (len-mid) elements, from mid to len-1
         */
        L = (int*) malloc ( mid * sizeof(int) );
        R = (int*) malloc ( (len - mid) * sizeof(int) );

        for(i = 0; i < mid; i++)
                L[i] = arr[i];

        for(i = mid; i < len; i++)
                R[i-mid] = arr[i];

        /* Sort the left and right subarrays. */
        merge_sort(L, mid);
        merge_sort(R, len-mid);

        /* Merging L and R into arr as sorted array. */
        merge_array(arr, L, mid, R, len-mid);

        free(L);
        free(R);
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
