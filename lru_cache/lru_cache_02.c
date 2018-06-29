/* Use queue (FIFO) and hash table to implement the Least Recently Used (LRU) cache.
 *
 * http://www.geeksforgeeks.org/lru-cache-implementation/
 */

#include <stdio.h>
#include <stdlib.h>

#define LRU_CACHE_SIZE 5

/* A node which use doubly linked list to implement a queue.
 * The page_number store the number of the page.
 */
typedef struct node {
	unsigned page_number;
	struct node * prev, * next;
} node_t;

/* Queue. */
typedef struct queue {
	unsigned count;
	unsigned frame_number;
	struct node * front, * rear;
} queue_t;

/* Hash. */
typedef struct hash_table {
	int capacity;
	struct node ** array;
} hash_table_t;

/* Node create. */
node_t * node_create(unsigned page_number)
{
	node_t * tmp = malloc( sizeof(*tmp) );

	tmp->page_number = page_number;
	tmp->prev = tmp->next = NULL;

	return tmp;
}

/* Queue create. */
queue_t * queue_create(int frame_number)
{
	queue_t * queue = malloc( sizeof( *queue ) );

	queue->count = 0;
	queue->front = queue->rear = NULL;
	queue->frame_number = frame_number;

	return queue;
}

/* Hash table create. */
hash_table_t * hash_table_create(int capacity)
{
	hash_table_t * hash_table = malloc( sizeof( *hash_table ) );
	hash_table->capacity = capacity;

	hash_table->array = (node_t **) malloc( hash_table->capacity * sizeof( node_t * ) );

	/* Initialize all hash_table entries as empty. */
	int i;
	for( i = 0; i < hash_table->capacity; i++ ){
                hash_table->array[i] = NULL;
        }

	return hash_table;
}

/* Is frame full. */
int is_frame_full(queue_t * queue)
{
	return (queue->count == queue->frame_number);
}

/* if queue is empty. */
int is_queue_empty(queue_t * queue)
{
	return (queue->rear == NULL);
}

/* Delete a node from queue. */
void queue_pop(queue_t * queue)
{
	if( is_queue_empty(queue) )
		return;

	/* If this is the only node in list. */
	if (queue->front == queue->rear){
		queue->front = NULL;
        }

	/* Remove the rear node of queue to implement FIFO. */
	node_t * tmp = queue->rear;
	queue->rear = queue->rear->prev;

	if (queue->rear){
		queue->rear->next = NULL;
        }

	free( tmp );
	queue->count--;
}

/* Insert a node into queue. */
void queue_insert(queue_t * queue, hash_table_t * hash_table, unsigned page_number)
{
	/* Remove page from hash_table. */
	if ( is_frame_full(queue) ) {
		hash_table->array[queue->rear->page_number] = NULL;
		queue_pop(queue);
	}

	node_t * tmp = node_create(page_number);
	/* FIFO. */
	tmp->next = queue->front;

	/* The first node of the queue needs to modify the rear and front. */
	if ( is_queue_empty(queue) ){
		queue->rear = queue->front = tmp;
	}
	/* Only need to insert a node before the front node. */
	else {
		queue->front->prev = tmp;
		queue->front = tmp;
	}

	hash_table->array[page_number] = tmp;
	queue->count++;
}


void lru_cache( queue_t * queue, hash_table_t * hash_table, unsigned page_number )
{
	node_t * request_page = hash_table->array[page_number];

	/* The page is not in cache. */
	if ( request_page == NULL ){
                queue_insert(queue, hash_table, page_number);
        }

	/* The page is there and not at front. */
	else if (request_page != queue->front)
	{
		/* Unlink rquested page from its current location in queue. */
		request_page->prev->next = request_page->next;
		if (request_page->next){
			request_page->next->prev = request_page->prev;
		}

		/* If the requested page is rear. */
		if (request_page == queue->rear) {
        		queue->rear = request_page->prev;
        		queue->rear->next = NULL;
		}

		/* Put the requested page before current front. */
		request_page->next = queue->front;
		request_page->prev = NULL;

		request_page->next->prev = request_page;
		queue->front = request_page;
	}
}

void queue_free(queue_t * queue)
{
	node_t * tmp = NULL;
	while(queue->front != NULL){
		tmp = queue->front;
		queue->front = queue->front->next;
		free(tmp);
	}
	free(queue);
}

void hash_table_free(hash_table_t * hash_table)
{
	free(hash_table->array);
	free(hash_table);
}

int main()
{
        int i;
        int page_array[] = {1, 3, 5, 1, 4, 5, 8, 4, 5, 1, 4, 3, 5, 1};
	// int page_array[] = {1, 3, 5, 1, 5, 1, 5};

        int page_arr_len = sizeof(page_array) / sizeof(int);

	queue_t * q = queue_create( LRU_CACHE_SIZE );
	hash_table_t * ht = hash_table_create( page_arr_len );

        for (i = 0; i < page_arr_len; i++){
                lru_cache( q, ht, page_array[i]);
        }

        node_t * tmp_node = q->front;
        for (i = 0; i < LRU_CACHE_SIZE; i++){
                printf ("%d ", tmp_node->page_number);
                tmp_node = tmp_node->next;
        }
        printf("\n");

	/* Free. */
	queue_free(q);
	hash_table_free(ht);

	return 0;
}
