#include <stdbool.h>
#include "graphs.h"

/**
 * dfs_traverse_rec - side-effectful recursive helper for
 * *		      `depth_first_traverse` function
 * @v: pointer to a vertex_t in a graph_t's vertices list
 * @visited: bool array for visited flags corresponding to vertex_t indices
 * @depth: size_t current depth in the traversal
 * @action: pointer to function called for eacch visited vertex
 * Return: size_t depth after visiting each vertex_t in adjacency list
 */
static size_t dfs_traverse_rec(const vertex_t *v, bool *visited, size_t depth,
			       void (*action)(const vertex_t *, size_t))
{
	edge_t *e;
	size_t max_depth = depth;

	visited[v->index] = true;
	action(v, depth);

	for (e = v->edges; e; e = e->next)
		if (e->dest && !visited[e->dest->index])
		{
			size_t curr_depth = dfs_traverse_rec(e->dest, visited, depth + 1, action);
			if (curr_depth > max_depth)
				max_depth = curr_depth;
		}

	return (max_depth);
}

/**
 * depth_first_traverse - depth-first traversal of a graph_t
 * *			  while calling a function on each vertex_t
 * @graph: pointer to the graph_t to traverse
 * @action: pointer to function to be called for each visited vertex
 * *	    taking a vertex_t pointer and its current depth
 * Return: size_t depth of deepest vertex, or 0 on failure
 */
size_t depth_first_traverse(const graph_t *graph,
			    void (*action)(const vertex_t *, size_t))
{C99(
	if (!graph || !action || !graph->nb_vertices)
		return (0);
	bool *visited = calloc(graph->nb_vertices, sizeof(*visited));
	if (!visited) return (0);
	size_t depth = dfs_traverse_rec(graph->vertices, visited, 0, action);
	free(visited);
	return (depth););
}
