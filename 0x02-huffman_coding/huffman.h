#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stddef.h>

#include "heap.h"

#define RED	"\033[0;31m"
#define BLUE	"\033[0;34m"
#define NC	"\033[0m"

/**
 * struct symbol_s - Stores a char and its associated frequency
 *
 * @data: The character
 * @freq: The associated frequency
 */
typedef struct symbol_s
{
	char data;
	size_t freq;
} symbol_t;

symbol_t *symbol_create(char data, size_t freq);
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size);
int huffman_extract_and_insert(heap_t *priority_queue);
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size);
int huffman_codes(char *data, size_t *freq, size_t size);


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wvariadic-macros"

#ifdef PRINT_NODE_ARRAY
#undef PRINT_NODE_ARRAY
#endif
#if USING_SYMBOL_NODE
void print_int_node_array(const node_t **, size_t);
#define PRINT_NODE_ARRAY print_int_node_array
#else
void print_symbol_node_array(const node_t **array, size_t size);
#define PRINT_NODE_ARRAY print_symbol_node_array
#endif

#ifndef C99
#define C99(...) \
do { \
_Pragma("GCC diagnostic push")\
_Pragma("GCC diagnostic ignored \"-Wpedantic\"")\
_Pragma("GCC diagnostic ignored \"-Wvla\"")\
	__VA_ARGS__ \
_Pragma("GCC diagnostic pop")\
} while (0)
#endif /* C99 */

#ifndef DBG
#if !RELEASE
#include <stdio.h>
#define DBG(...) C99(do {printf("%s:%d: ", __func__, __LINE__); __VA_ARGS__;} while (0););
#else
#define DBG(...)
#endif
#endif

#pragma GCC diagnostic pop

#endif /* HUFFMAN_H */
