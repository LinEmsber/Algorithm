/* Merge two sorted linked lists */

#include <stdio.h>
#include <stdlib.h>


/* Link list node */
struct node
{
	int data;
	struct node * next;
};

/* Take the front node of the source to the end of destination. */
void move_node(struct node ** destRef, struct node ** sourceRef)
{
	struct node * newNode = *sourceRef;
	if (newNode == NULL)
		return ;

	*sourceRef = newNode->next;
	newNode->next = *destRef;
	*destRef = newNode;
}

/* Takes two lists sorted in increasing order, and splices their nodes together to make one big sorted list which is returned. */
struct node * merge_two_list(struct node * node_a, struct node * node_b)
{
	struct node tmp_node;

	struct node * tail = &tmp_node;
	tmp_node.next = NULL;

	while (1) {
		/* If the list is the out of node, use the other list. */
		tail->next = node_b;
		if (node_a == NULL) {
			break;
		}
		else if (node_b == NULL) {
			tail->next = node_a;
			break;
		}

		if (node_a->data <= node_b->data){
			move_node(&(tail->next), &node_a);
		} else {
			move_node(&(tail->next), &node_b);
		}

		tail = tail->next;
	}

	return tmp_node.next;
}


void push(struct node ** head_ref, int new_data)
{
	struct node * new_node = (struct node *) malloc(sizeof(struct node));

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
	struct node * merged_list = NULL;
	struct node * list_a = NULL;
	struct node * list_b = NULL;

	/* 80 -> 70 -> 40 -> 30 -> 50 -> 10 */
	push(&list_a, 80);
	push(&list_a, 70);
	push(&list_a, 50);
	push(&list_a, 40);
	push(&list_a, 30);
	push(&list_a, 10);

	/* 60 -> 150 -> 40 -> 130 -> 20 -> 90 */
	push(&list_b, 150);
	push(&list_b, 130);
	push(&list_b, 90);
	push(&list_b, 60);
	push(&list_b, 40);
	push(&list_b, 20);

	merged_list = merge_two_list(list_a, list_b);

	printf("Merged Linked List is: \n");
	print_list(merged_list);

	return 0;
}
