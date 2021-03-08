#include "rb_trees.h"

/**
 * array_to_rb_tree - builds a red-black tree from an array
 * @array: pointer to first element of array to convert
 * @size: number of elements in array
 *
 * Values already present will be ignored, rb_tree_insert malloc fail will
 * not return NULL
 * Return: pointer to root node of generated red-black tree, NULL on failure
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	size_t i;
	rb_tree_t *root;

	root = NULL;
	for (i = 0; array && i < size; ++i)
		rb_tree_insert(&root, array[i]);
	return (root);
}
