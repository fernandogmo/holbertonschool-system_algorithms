#include "rb_trees.h"

/**
 * repair_lsibling - sibling of node is to the right
 * @root: double pointer to root node
 * @node: pointer to node where violation detected
 * @node_parent: pointer to parent of node
 *
 * Return: pointer to node
 */
rb_tree_t *repair_lsibling(rb_tree_t **root, rb_tree_t *node,
		rb_tree_t *node_parent)
{
	rb_tree_t *sibling;

	sibling = node ? node->parent->left : node_parent->left;
	if (sibling && sibling->color == RED)
	{
		sibling->color = BLACK;
		node_parent->color = RED;
		rotl(root, node_parent);
		sibling = node ? node->parent->left : node_parent->left;
	}
	if (sibling && (!sibling->right || sibling->right->color == BLACK)
			&& (!sibling->left || sibling->left->color == BLACK))
	{
		sibling->color = RED;
		node = node ? node->parent : node_parent;
	}
	else
	{
		if (sibling && (!sibling->left ||
					sibling->left->color == BLACK))
		{
			sibling->right->color = BLACK;
			sibling->color = RED;
			rotr(root, sibling);
			sibling = node ? node->parent->left :
				node_parent->left;
		}
		if (sibling)
		{
			sibling->color = node_parent->color;
			if (sibling->left)
				sibling->left->color = BLACK;
		}
		node_parent->color = BLACK;
		if (sibling->left)
			sibling->left->color = BLACK;
		rotl(root, node_parent);
		node = *root;
	}
	return (node);
}

/**
 * repair_rsibling - sibling of node is to the right
 * @root: double pointer to root node
 * @node: pointer to node where violation detected
 * @node_parent: pointer to parent of node
 *
 * Return: pointer to node
 */
rb_tree_t *repair_rsibling(rb_tree_t **root, rb_tree_t *node,
		rb_tree_t *node_parent)
{
	rb_tree_t *sibling;

	sibling = node ? node->parent->right : node_parent->right;
	if (sibling && sibling->color == RED)
	{
		sibling->color = BLACK;
		node_parent->color = RED;
		rotl(root, node_parent);
		sibling = node ? node->parent->right : node_parent->right;
	}
	if (sibling && (!sibling->left || sibling->left->color == BLACK) &&
			(!sibling->right || sibling->right->color == BLACK))
	{
		sibling->color = RED;
		node = node ? node->parent : node_parent;
	}
	else
	{
		if (sibling && (!sibling->right ||
					sibling->right->color == BLACK))
		{
			sibling->left->color = BLACK;
			sibling->color = RED;
			rotr(root, sibling);
			sibling = node ? node->parent->right :
				node_parent->right;
		}
		if (sibling)
		{
			sibling->color = node_parent->color;
			if (sibling->right)
				sibling->right->color = BLACK;
		}
		node_parent->color = BLACK;
		if (sibling->right)
			sibling->right->color = BLACK;
		rotl(root, node_parent);
		node = *root;
	}
	return (node);
}

/**
 * rb_rm_repair - fixes red-black tree violations after a node has been removed
 * @root: double pointer to root node
 * @node: pointer to node where violation detected
 * @node_parent: pointer to parent of node
 */
void rb_rm_repair(rb_tree_t **root, rb_tree_t *node, rb_tree_t *node_parent)
{
	while (node != *root && (!node || node->color == BLACK))
	{
		if (node == node_parent->left)
			node = repair_rsibling(root, node, node_parent);
		else
			node = repair_lsibling(root, node, node_parent);
	}
	if (node)
		node->color = BLACK;
}

/**
 * rb_transplant - transplants src node with tar
 * @root: pointer to root node
 * @tar: node to transplant
 * @src: node being transplanted
 *
 * If tar is the root node then points root to src
 * Return: pointer to root node
 */
rb_tree_t *rb_transplant(rb_tree_t *root, rb_tree_t *tar, rb_tree_t *src)
{
	if (!tar->parent)
		root = src;
	else if (tar == tar->parent->left)
		tar->parent->left = src;
	else
		tar->parent->right = src;
	if (src)
		src->parent = tar->parent;
	return (root);
}

/**
 * min_transplant - gets the minimum value node and calls transplant
 * @root: double pointer to root node
 * @rm_node: pointer to node being removed
 * @rm_node_cpy: pointer to copy of node being removed
 * @rm_node_cpy_color: stores color value of rm_node_cpy
 * @node: pointer to node where violation detected
 * @node_parent: double pointer to node's parent
 *
 * Continuation of rb_tree_remove else logic
 */
void min_transplant(rb_tree_t **root, rb_tree_t *rm_node,
		rb_tree_t *rm_node_cpy, int *rm_node_cpy_color,
		rb_tree_t *node, rb_tree_t **node_parent)
{
	rb_tree_t *min;

	min = rm_node->right;
	GET_MIN(min);
	rm_node_cpy = min;
	*rm_node_cpy_color = rm_node_cpy->color;
	node = rm_node_cpy->right;
	if (node && rm_node_cpy->parent == rm_node)
	{
		*node_parent = node->parent = rm_node_cpy;
	}
	else
	{
		*node_parent = rm_node_cpy->parent;
		*root = rb_transplant(*root, rm_node_cpy,
				rm_node_cpy->right);
		rm_node_cpy->right = rm_node->right;
		if (rm_node_cpy->right)
			rm_node_cpy->right->parent = rm_node_cpy;
	}
	*root = rb_transplant(*root, rm_node, rm_node_cpy);
	rm_node_cpy->left = rm_node->left;
	rm_node_cpy->left->parent = rm_node_cpy;
	rm_node_cpy->color = rm_node->color;
}

/**
 * rb_tree_remove - removes a node from red-black tree
 * @root: pointer to root node
 * @n: value to remove from tree
 *
 * root		T
 * rm_node	z
 * rm_node_cpy	y
 * node		x
 * Return: pointer to root node
 */
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n)
{
	rb_tree_t *rm_node, *rm_node_cpy, *node, *node_parent;
	int rm_node_cpy_color;

	rm_node = root;
	node = NULL;
	GET_NODE(rm_node, n);
	rm_node_cpy = rm_node;
	if (!rm_node)
		return (NULL);
	rm_node_cpy_color = rm_node_cpy->color;
	if (!rm_node->left)
	{
		node = rm_node->right;
		if (!node)
			node_parent = rm_node->parent;
		root = rb_transplant(root, rm_node, rm_node->right);
	}
	else if (!rm_node->right)
	{
		node = rm_node->left;
		if (!node)
			node_parent = rm_node->parent;
		root = rb_transplant(root, rm_node, rm_node->left);
	}
	else
	{
		min_transplant(&root, rm_node, rm_node_cpy, &rm_node_cpy_color,
				node, &node_parent);
	}
	free(rm_node);
	if (rm_node_cpy_color == BLACK)
		rb_rm_repair(&root, node, node_parent);
	return (root);
}
