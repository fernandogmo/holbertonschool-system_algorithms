#include "graphs.h"

/**
 * graph_delete - completely deallocates a graph_t
 * @graph: pointer to the graph_t to be deleted
 */
void graph_delete(graph_t *graph)
{
	if (!graph)
		return;
	FREE(vertex_t, v, graph->vertices, free(v->content);
	     FREE(edge_t, e, v->edges, NULL;););
	free(graph);
}
