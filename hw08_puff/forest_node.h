/* forest_node.h

   Prototypes for functions on a singly-linked list
*/

#ifndef FROEST_NODE_H_
#define FOREST_NODE_H_

#include "huff_tree_node.h"

typedef struct forest_node{
  huff_tree_node* data;
  struct forest_node* next; // pointer to next node
}forest_node;

// create (i.e., malloc) a new node
forest_node* forest_node_new(huff_tree_node* data, forest_node* next);

// insert a new node after the given one
// Precondition: Supplied node is not NULL.
void forest_node_insert_after(forest_node* n, huff_tree_node* data);

// return a pointer to the nth node in the list. If n is
// the length of the list, this returns NULL, but does not error.
// Precondition: the list has at least n nodes
forest_node* nth_node(forest_node* head, int n);

// free an entire linked list. The list might be empty.
void forest_node_free(forest_node* head);

#endif
