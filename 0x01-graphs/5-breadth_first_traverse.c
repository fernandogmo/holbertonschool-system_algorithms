#include "graphs.h"

/**
 * breadth_first_traverse - breadth-first traversal of a graph_t
 * *			  while calling a function on each vertex_t
 * @graph: pointer to the graph_t to traverse
 * @action: pointer to function to be called for each visited vertex
 * *	    taking a vertex_t pointer and its current depth
 * Return: size_t depth of deepest vertex, or 0 on failure
 */
size_t breadth_first_traverse(const graph_t *graph,
			      void (*action)(const vertex_t *, size_t))
{
	if (!graph || !graph->nb_vertices || !graph->vertices || !action)
		return (0);

	return (1);
}
