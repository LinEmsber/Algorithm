/* The implementation of Kruskal’s Minimum Spanning Tree Algorithm.
 * Reference: https://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The structure of a weighted edge. */
struct edge{
	int src, dest, weight;
};

/* A structure of a connected, undirected, and weighted graph. */
struct graph
{
	int num_vertex, num_edge;

	/* An array of edges. */
	struct edge * edge;
};

/* Creates a graph with number of vertex and number of edge. */
struct graph * createGraph(int num_vertex, int num_edge)
{
	struct graph * graph = (struct graph *) malloc (sizeof(struct graph));
	graph->num_vertex = num_vertex;
	graph->num_edge = num_edge;

	graph->edge = (struct edge *) malloc(sizeof(struct edge) * num_edge);

	return graph;
}

/* A structure to represent a subset for union-find. */
struct subset{
	int parent;
	int rank;
};

/* A function to find set of an element. */
int find(struct subset subsets[], int i)
{
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

/* A function that does union of two sets of x and y. */
void union_edges(struct subset subsets[], int x, int y)
{
	int x_root = find(subsets, x);
	int y_root = find(subsets, y);

	/* Attach smaller rank tree under root of high rank tree (union_edges by Rank). */
	if (subsets[x_root].rank < subsets[y_root].rank) {
                subsets[x_root].parent = y_root;

        } else if (subsets[x_root].rank > subsets[y_root].rank) {
		subsets[y_root].parent = x_root;

        } else {
                /* If ranks are same, then make one as root and increment its rank by one. */
		subsets[y_root].parent = x_root;
		subsets[x_root].rank++;
	}
}

/* The comparison function of two edges according to their weights.
 * This function is called by qsort().
 */
int compare_weight(const void * a, const void * b)
{
	struct edge * a1 = (struct edge *)a;
	struct edge * b1 = (struct edge *)b;
	return a1->weight > b1->weight;
}

/* function to construct MST using Kruskal's algorithm. */
struct edge * Kruskal_MST(struct graph * graph)
{
        int i;
        int edge_index = 0;
	int num_vertex = graph->num_vertex;
	struct edge * result = (struct edge *) malloc( sizeof(struct edge) * num_vertex);

	/* Allocate the memory for creating subsets. */
	struct subset * subsets = (struct subset*) malloc( num_vertex * sizeof(struct subset) );

	/* Initialize the subsets with single elements. */
	for (i = 0; i < num_vertex; ++i) {
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}

        /* Sort all the edges in non-decreasing order of their weight.
         * If we are not allowed to change the given graph, we can create a copy of array of edges.
         */
        qsort(graph->edge, graph->num_edge, sizeof(graph->edge[0]), compare_weight);

        /* Pick the smallest edge and increment the index for next iteration. */
        for ( i = 0; i < num_vertex ; i++) {

                struct edge next_edge = graph->edge[i];
		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		/* If including this edge does not cause the cycle, include it in result. */
		if (x != y) {
			result[edge_index] = next_edge;
                        edge_index++;
			union_edges(subsets, x, y);
		}
	}

	/* print out. */
        printf("edge index: %d\n", edge_index);

        return result;
}

void print_MST(struct edge * MST_edge, int edge_length)
{
        printf("Following are the edges in the constructed Minimum Spanning Tree (MST)\n");
        for (int i = 0; i < edge_length; ++i)
                printf("%d -- %d == %d\n", MST_edge[i].src, MST_edge[i].dest, MST_edge[i].weight);
}

int main()
{
	/* Let us create following weighted graph
	   10
	   0--------1
	   |  \     |
	   6|   5\   |15
	   |      \ |
	   2--------3
	   4       */
	int num_vertex = 4;
	int num_edge = 5;
	struct graph * graph_object = createGraph(num_vertex, num_edge);

	// add edge 0-1
	graph_object->edge[0].src = 0;
	graph_object->edge[0].dest = 1;
	graph_object->edge[0].weight = 10;

	// add edge 0-2
	graph_object->edge[1].src = 0;
	graph_object->edge[1].dest = 2;
	graph_object->edge[1].weight = 6;

	// add edge 0-3
	graph_object->edge[2].src = 0;
	graph_object->edge[2].dest = 3;
	graph_object->edge[2].weight = 5;

	// add edge 1-3
	graph_object->edge[3].src = 1;
	graph_object->edge[3].dest = 3;
	graph_object->edge[3].weight = 15;

	// add edge 2-3
	graph_object->edge[4].src = 2;
	graph_object->edge[4].dest = 3;
	graph_object->edge[4].weight = 4;

	struct edge * edge_list = Kruskal_MST(graph_object);

        print_MST(edge_list, 3);

	return 0;
}
