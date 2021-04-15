#include "graphs.h"

/**
 * link_vertex - links a source vertex to a destination vertex
 * @src: pointer to vertex_t where edge will be added
 * @dst: pointer to vertex_t for `dest` value in @src
 * Return: 1 on success, or 0 on failure
 */
static int link_vertex(vertex_t *src, vertex_t *dst)
{
	edge_t *last = src->edges, *e = calloc(1, sizeof(*e));

	if (e)
	{
		e->dest = dst;
		if (!last)
			src->edges = e;
		else
		{
			while (last->next)
				last = last->next;
			last->next = e;
		}
		return (1);
	}
	free(e);
	return (0);
}

/**
 * graph_add_edge - adds an edge between two vertices to an existing graph
 * @graph: graph_t where we add vertex_t
 * @src: string identifying the vertex to make the connection from
 * @dst: string identifying the vertex to connect to
 * @type: enum value of UNIDIRECTIONAL or BIDIRECTIONAL
 * Return: 1 on success, or 0 on failure
 */
int graph_add_edge(graph_t *graph,
		   const char *src,
		   const char *dst,
		   edge_type_t type)
{
	vertex_t *src_v	= graph ? graph->vertices : NULL;
	vertex_t *dst_v	= graph ? graph->vertices : NULL;

	if (!graph || !src || !*src || !dst || !*dst ||
	    !(type == 0 || type == 1))
		goto fail;
	for (; src_v; src_v = src_v->next)
		if (!strcmp(src_v->content, src))
			break;
	for (; dst_v; dst_v = dst_v->next)
		if (!strcmp(dst_v->content, dst))
			break;
	if (!dst_v || !src_v || !link_vertex(src_v, dst_v))
		goto fail;
	if (type == BIDIRECTIONAL && !link_vertex(dst_v, src_v))
		goto fail;
	return (1);
fail:
	return (0);
}
