/* tree_noe.c

   Implements functions working with binary tree nodes.
*/

#include <stdlib.h>
#include <stdio.h>

#include "tree_node.h"

// create (i.e., malloc) a new node
tree_node* new_node(char* key, movie* value, tree_node* left, tree_node* right)
{
  tree_node* new = malloc(sizeof(tree_node));
  new->key = key;
  new->value = value;
  new->left = left;
  new->right = right;
  return new;
}

// free all nodes in a binary tree. Does not free any strings.
void free_tree(tree_node* root)
{
  if(root)
  {  
    free_tree(root->left);
    free_tree(root->right);
    free(root);
  }
}

// returns the number of nodes in the tree
int size(tree_node* root)
{
  if(root)
  {
    return 1 + size(root->left) + size(root->right);
  }
  else
  {
    return 0;
  }
}

