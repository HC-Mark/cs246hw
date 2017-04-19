/* llist.h

   Declarations for an abstract sequence type backed by a singly linked list.
*/

#ifndef LLIST_H_
#define LLIST_H_

#include "forest_node.h"
// An abstract type for sequences
typedef struct forest_record* forest;

// return an empty llist. Make sure to call llist_free when you're done
// with it.
forest forest_new();

// returns the number of elements in the llist. Runs in constant time.
int forest_size(forest l);

// appends a new element to the beginning of the llist. Runs in constant time.
void forest_push(forest l, huff_tree_node* node);

// removes and returns the first element in the llist. Runs in constant time.
// precondition: there is at least one element in the llist.
huff_tree_node* forest_pop(forest l);

// returns the first element in the llist, without changing the llist.
// Runs in constant time.
// precondition: there is at least one element in the llist.
huff_tree_node* forest_peek(forest l);

// adds a new element into the llist, after n existing elements.
// Takes O(n) steps.
// precondition: the list has at least n elements
void forest_insert(forest l, huff_tree_node* node);

// retrieves the nth element of the llist. Takes O(n) steps.
// precondition: the list has at least (n+1) elements
huff_tree_node* forest_get(forest l, int n);

// access the underlying head llist_node. Useful for iteration.
forest_node* forest_head(forest l);

// frees an llist. Takes O(size(l)) steps.
void forest_free(forest l);

#endif
