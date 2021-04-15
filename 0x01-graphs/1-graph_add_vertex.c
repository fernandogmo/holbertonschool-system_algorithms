#include "graphs.h"

/**
 * graph_add_vertex - allocates and initializes vertex_t in graph_t
 * @graph: graph_t where we add vertex_t
 * @str: value at new vertex_t in @graph
 * Return: pointer to new vertex_t, or NULL on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *v = calloc(1, sizeof(vertex_t));
	vertex_t *p = graph ? graph->vertices : NULL;

	if (!graph || !str || !*str || !v)
		goto fail;
	if (!p)
		graph->vertices = v;
	else
	{
		for (; p->next; p = p->next)
			if (!strcmp(p->content, str))
				goto fail;
		p->next = v;
	}
	v->index = graph->nb_vertices++;
	v->content = strdup(str);
	return (v);
fail:
	free(v);
	return (NULL);
}
