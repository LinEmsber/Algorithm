/* Merge sort the elements of the linked list.
 * Input a linked list to this function and use merge sort to sort the elements of list.
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node * next;
};

/* Prototypes */
void merge_sort_linked_list(struct node ** root);
struct node * merge_sorted_list_2(struct node * node_a, struct node * node_b);
void node_move(struct node ** dest_node, struct node ** src_node);
void split_list(struct node * root_src, struct node ** front_list_ptr, struct node ** back_root_ptr);

/* sorts the linked list. */
void merge_sort_linked_list(struct node ** root_src)
{
	struct node * root = *root_src;
	struct node * list_a;
	struct node * list_b;

	if ( (root == NULL) || (root->next == NULL) )
		return;

	/* Split root into 'list_a' and 'list_b' sublists */
	split_list(root, &list_a, &list_b);

	/* Recursively sort the sublists */
	merge_sort_linked_list(&list_a);
	merge_sort_linked_list(&list_b);

	/* answer = merge the two sorted lists together */
	*root_src = merge_sorted_list_2(list_a, list_b);
}

struct node * merge_sorted_list_2(struct node * node_a, struct node * node_b)
{
	struct node * result = NULL;

	if (node_a == NULL){
		return node_b;
	} else if (node_b == NULL) {
		return node_a;
	} else {

		/* Pick either node_a or node_b and use recrusive method for the next node. */
		if (node_a->data <= node_b->data) {
			result = node_a;
			result->next = merge_sorted_list_2(node_a->next, node_b);
		} else {
			result = node_b;
			result->next = merge_sorted_list_2(node_a, node_b->next);
		}
	}

	return result;
}

/* Split the nodes of the given list into front and back halves and return the two lists
 * using the reference parameters.
 */
void split_list(struct node * root_src, struct node ** front_list_ptr, struct node ** back_root_ptr)
{
	struct node * slow = root_src;
	struct node * fast = root_src->next;

	/* The fast moves two nodes once a time and the slow moves one node once a time. */
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	/* The slow is before the middle point. */
	*front_list_ptr = root_src;
	*back_root_ptr = slow->next;
	slow->next = NULL;
}

void push(struct node ** head_ref, int new_data)
{
	struct node * new_node = (struct node *) malloc( sizeof(struct node) );

	new_node->data = new_data;
	new_node->next = (*head_ref);

	*head_ref = new_node;
}

void print_list(struct node * node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

int main()
{
	struct node * list_a = NULL;

	/* Push the contents to the list. */
	push(&list_a, 15);
	push(&list_a, 100);
	push(&list_a, 35);
	push(&list_a, 20);
	push(&list_a, 30);
	push(&list_a, 85);
	push(&list_a, 70);
	push(&list_a, 22);

	printf("Before merge sort, the list: \n");
	print_list(list_a);

	merge_sort_linked_list(&list_a);

	printf("After merge sort, the list: \n");
	print_list(list_a);

	return 0;
}
