/* Prim's Minimum Spanning Tree (MST) algorithm.
 * The program is for adjacency matrix representation of the graph.
 */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define NUM_V 9

/* Print the constructed MST stored in parent[]. */
void print_MST(int parent[], int n, int graph[NUM_V][NUM_V])
{
	printf("Edge   Weight\n");
	for (int i = 1; i < NUM_V; i++)
	printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

/* Find the vertex with minimum key value from the set of vertices not yet included in MST. */
int min_key(int key[], bool MST_set[])
{
	int min = INT_MAX, min_index;

	for (int i = 0; i < NUM_V; i++) {
		if (MST_set[i] == false && key[i] < min) {
			min = key[i];
			min_index = i;
		}
	}

	return min_index;
}

/* Construct the MST of a graph represented using adjacency matrix representation.*/
void prim_MST(int graph[NUM_V][NUM_V])
{
	bool MST_set[NUM_V];
	int parent[NUM_V];
	int key[NUM_V];

	parent[0] = -1;

	for (int i = 0; i < NUM_V; i++){
		key[i] = INT_MAX;
		MST_set[i] = false;
	}
	key[0] = 0;

	for (int count = 0; count < NUM_V - 1; count++) {
		/* Pick the minimum key vertex from the set of vertices not yet included in MST. */
		int u = min_key(key, MST_set);

		/* Add the picked vertex to the MST Set. */
		MST_set[u] = true;

		/* Update the key value and the parent index of the adjacent vertices of the picked vertex.
		 * Consider only those vertices which are not yet included in the MST.
		 */
		for (int v = 0; v < NUM_V; v++){

			/* Update the key only if graph[u][v] is smaller than key[v]. */
			if (graph[u][v] && MST_set[v] == false && graph[u][v] <  key[v]){
				parent[v]  = u;
				key[v] = graph[u][v];
			}
		}
	}

	/* Print the constructed MST. */
	print_MST(parent, NUM_V, graph);
}

int main()
{
	/* Let us create the following graph
	   8      7
	   (1)----(2)-----(3)
         / |   2  | \     |  \ 9
     4 /   |     (8) \    |    \
     (0)11 |    / |   \4  |14  (4)
     8 \   |  /7  |6   \  |   /
        \  |/     |      \| /  10
	  (7)-----(6)----(5)
	   1       2
	   */
	int graph[NUM_V][NUM_V] = {
		{0, 4, 0, 0, 0, 0, 0, 8, 0},
		{4, 0, 8, 0, 0, 0, 0, 11, 0},
		{0, 8, 0, 7, 0, 4, 0, 0, 2},
		{0, 0, 7, 0, 9, 14, 0, 0, 0},
		{0, 0, 0, 9, 0, 10, 0, 0, 0},
		{0, 0, 4, 14, 10, 0, 2, 0, 0},
		{0, 0, 0, 0, 0, 2, 0, 1, 6},
		{8, 11, 0, 0, 0, 0, 1, 0, 7},
		{0, 0, 2, 0, 0, 0, 6, 7, 0}
	};

	prim_MST(graph);

	return 0;
}
