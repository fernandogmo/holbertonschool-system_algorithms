#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

/**
 * struct binary_tree_node_s - Binary tree node data structure
 *
 * @data: Data stored in a node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 * @parent: Pointer to the parent node
 */
typedef struct binary_tree_node_s
{
	void *data;
	struct binary_tree_node_s *left;
	struct binary_tree_node_s *right;
	struct binary_tree_node_s *parent;
} binary_tree_node_t;

/**
 * struct heap_s - Heap data structure
 *
 * @size: Size of the heap (number of nodes)
 * @data_cmp: Function to compare two nodes data
 * @root: Pointer to the root node of the heap
 */
typedef struct heap_s
{
	size_t size;
	int (*data_cmp)(void *, void *);
	binary_tree_node_t *root;
} heap_t;

typedef binary_tree_node_t node_t;

heap_t *heap_create(int (*data_cmp)(void *, void *));
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data);
binary_tree_node_t *heap_insert(heap_t *heap, void *data);
void *heap_extract(heap_t *heap);
void heap_delete(heap_t *heap, void (*free_data)(void *));

void binary_tree_print(const binary_tree_node_t *root,
		       int (*print_data)(char *, void *));
void print_node_array(const node_t **, size_t);


#define SWAP(a, b)                   \
	do {                         \
		const int tmp = (a); \
		(a) = (b);           \
		(b) = tmp;           \
	} while (0)

#define DATASWAP(a, b)			\
	do {				\
		void *tmp = (a->data);	\
		(a->data) = (b->data);	\
		(b->data) = tmp;	\
	} while (0)

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wvariadic-macros"

#ifndef C99
#define C99(...) \
do { \
_Pragma("GCC diagnostic push")\
_Pragma("GCC diagnostic ignored \"-Wpedantic\"")\
	__VA_ARGS__ \
_Pragma("GCC diagnostic pop")\
} while (0)
#endif /* C99 */

#pragma GCC diagnostic pop

#endif /* HEAP_H */
