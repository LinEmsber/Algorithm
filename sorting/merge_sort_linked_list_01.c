/* Merge sort in C */

#include<stdio.h>
#include<stdlib.h>

/* Linked list node. */
typedef struct node node_t;
struct node{
	int key;
	void * data;
	struct node * next;
};

/* Linked list. */

node_t * node_create(int value);
int node_insert_front(node_t * head, node_t * n);
int node_delete(node_t * head, int target_val);

node_t * node_create(int value)
{
	node_t * n;
	n = malloc( sizeof(*n) );
	if (n == NULL)
		return NULL;

	n -> key = value;
	n -> next = NULL;
	return n;
}

int node_insert_front(node_t * head, node_t * n)
{
	if (head == NULL || n == NULL)
		return -1;

	n -> next = head -> next;
	head -> next = n;

	return 0;
}

int node_delete(node_t * head, int target_key)
{
	int ret = -1;
	if (head == NULL)
		return ret;

	node_t **pp = &head;
	node_t *p = head;

	while(p){
		if(p->key == target_key){
			*pp = p->next;
			free(p);
			ret = 0;

			/* Remember to break from the while loop. */
			break;
		}

		pp = &p->next;
		p = p->next;
	}

	return ret;
}

node_t * previous_node(node_t * head, node_t * target_node)
{
	if(head == target_node || head == NULL)
		return NULL;

	/* Start from the head node to find the target nodes's previous node. */
	node_t * current = head;
	node_t * prev = NULL;

	while(current){

		/* Find the target node */
		if (current == target_node)
			break;

		prev = current;
		current = current->next;
	}

	/* Return target nodes's previous node. */
	return prev;
}

int swap_nodes(node_t ** head, node_t ** node_1, node_t ** node_2)
{
	if (head == NULL|| node_1 == NULL || node_2 == NULL)
		return -1;

	node_t * first = *node_1;
	node_t * second = *node_2;
	node_t * first_prev, * second_prev;
	node_t * tmp = NULL;

	/* Find the target nodes's previous node. */
	first_prev = previous_node(*head, first);
	second_prev = previous_node(*head, second);

	/* Swap the previous nodes of both nodes. */
	if(first_prev)
		first_prev->next = second;
	else
		*head = *node_2;

	if(second_prev)
		second_prev->next = first;
	else
		*head = *node_1;

	/* Swap the next nodes of both nodes */
	tmp = first->next;
	first->next = second->next;
	second->next = tmp;

	return 0;
}

/* Print the list. */
int print_list_key(node_t * head)
{
	if (head == NULL)
		return -1;

	node_t * current = head;

	while ( current != NULL ){
		printf("%d ", current->key);
		current = current -> next;
	}
	printf("\n");

	return 0;
}





/* merge sort linked list. */
void merge_sort_linked_list(node_t * head)
{
	node_t * root = head;
	node_t * front_list, * end_list;

	// split list into two parts
	split_list(root, front_list, end_list);

	// merge sort list recursively
	merge_sort_linked_list(front_list);
	merge_sort_linked_list(end_list);

	// merge
	merge(front_list, end_list);
}

/* Merge sort. */
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
