/* The implementation of Dijkstra's shortest path algorithm.
 * Reference: https://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
 */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define NUM_V 9

/* Print the constructed MST stored in parent[]. */
void print_SPT(int set[], int n)
{
	printf("Vertex\tDistance from Source\n");
	for (int i = 0; i < n; i++)
		printf("%d\t%d\n", i, set[i]);
}

/* Find the vertex with minimum key value from the set of vertices not yet included in MST. */
int min_distance(int key[], bool MST_set[])
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
void prim_MST(int graph[NUM_V][NUM_V], int src)
{
	/* The set of shortest path tree, SPT_set, will true if vertex i is included in shortest path tree. */
	bool SPT_set[NUM_V];
	int distance_set[NUM_V];

	/* Initialize all distances as infinite and SPT_set[] as false. */
	for (int i = 0; i < NUM_V; i++){
		distance_set[i] = INT_MAX;
		SPT_set[i] = false;
	}

	distance_set[src] = 0;

	for (int count = 0; count < NUM_V-1; count++) {
		/* Pick the minimum distance vertex from the set of vertices not yet processed. */
		int u = min_distance(distance_set, SPT_set);

		SPT_set[u] = true;

		/* Update the value of the adjacent vertices of the picked vertex. */
		for (int v = 0; v < NUM_V; v++){
			if ( !SPT_set[v] && graph[u][v] &&
				distance_set[u] != INT_MAX && distance_set[u] + graph[u][v] < distance_set[v]){

				distance_set[v] = distance_set[u] + graph[u][v];
			}
		}
	}

	/* Print the constructed MST. */
	print_SPT(distance_set, NUM_V);
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

	prim_MST(graph, 0);

	return 0;
}
