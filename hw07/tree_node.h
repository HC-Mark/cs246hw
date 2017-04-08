/* tree_node.h

   Prototypes of functions for working with binary tree nodes.
*/

#ifndef TREE_NODE_H_
#define TREE_NODE_H_

#include "abstract_types.h"

typedef struct tree_node {
  // these are the data in each node
  char* key;
  movie* value;
  
  struct tree_node* left;
  struct tree_node* right;
} tree_node;

// create (i.e., malloc) a new node
tree_node* new_node(char* key, movie* value, tree_node* left, tree_node* right);

// free all nodes in a binary tree. Does not free any strings or movies.
void free_tree(tree_node* root);

// returns the number of nodes in the tree
int size(tree_node* root);

#endif
