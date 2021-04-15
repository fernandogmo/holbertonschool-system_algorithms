#ifndef GRAPHS_H
#define GRAPHS_H

#include <stdlib.h>
#include <string.h>

#define RED	"\033[0;31m"
#define BLUE	"\033[0;34m"
#define NC	"\033[0m"

/**
 * enum edge_type_e - Enumerates the different types of
 * connection between two vertices
 *
 * @UNIDIRECTIONAL: The connection is made only in one way
 * @BIDIRECTIONAL: The connection is made in two ways
 */
typedef enum edge_type_e
{
	UNIDIRECTIONAL = 0,
	BIDIRECTIONAL
} edge_type_t;

/* Define the structure temporarily for usage in the edge_t */
typedef struct vertex_s vertex_t;

/**
 * struct edge_s - Node in the linked list of edges for a given vertex
 * A single vertex can have many edges
 *
 * @dest: Pointer to the connected vertex
 * @next: Pointer to the next edge
 */
typedef struct edge_s
{
	vertex_t *dest;
	struct edge_s *next;
} edge_t;

/**
 * struct vertex_s - Node in the linked list of vertices in the adjacency list
 *
 * @index: Index of the vertex in the adjacency list.
 * @content: Custom data stored in the vertex (here, a string)
 * @nb_edges: Number of connections with other vertices in the graph
 * @edges: Pointer to the head node of the linked list of edges
 * @next: Pointer to the next vertex in the adjacency linked list
 *   This pointer points to another vertex in the graph, but it
 *   doesn't stand for an edge between the two vertices
 */
struct vertex_s
{
	size_t index;
	char *content;
	size_t nb_edges;
	edge_t *edges;
	struct vertex_s *next;
};

/**
 * struct graph_s - Representation of a graph
 * We use an adjacency linked list to represent our graph
 *
 * @nb_vertices: Number of vertices in our graph
 * @vertices: Pointer to the head node of our adjacency linked list
 */
typedef struct graph_s
{
	size_t nb_vertices;
	vertex_t *vertices;
} graph_t;

void graph_display(const graph_t *);
graph_t *graph_create(void);
vertex_t *graph_add_vertex(graph_t *graph, const char *str);
int graph_add_edge(graph_t *graph, const char *src, const char *dst, edge_type_t type);
void graph_delete(graph_t *graph);
size_t depth_first_traverse(const graph_t *graph, void (*action)(const vertex_t *, size_t));
size_t breadth_first_traverse(const graph_t *graph, void (*action)(const vertex_t *, size_t));


/* Use `xsnprintf` or `strlcpy` to replace `strdup` usage */
/* int xsnprintf(char *dst, size_t max, const char *fmt, ...); */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wvariadic-macros"
#define C99(...) \
do { \
_Pragma("GCC diagnostic push")\
_Pragma("GCC diagnostic ignored \"-Wpedantic\"")\
	__VA_ARGS__ \
_Pragma("GCC diagnostic pop")\
} while (0)

/*
 * FREE(vertex_t, v, graph->vertices,
 *	if(v->content)free(v->content);
 *	FREE(edge_t, e, v->edges, NULL;)
 *	;
 *     );
 */
#define FREE(xtype, xvar, xlist, ...) \
do { \
	xtype *xvar = xlist; \
	for (; xvar; free(xvar), xvar = xlist) \
	{ \
		__VA_ARGS__ \
		xlist = xvar->next; \
	} \
} while (0)
#pragma GCC diagnostic pop


#endif /* GRAPHS_H */
