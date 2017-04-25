/* huff_tree_node.c

   Implements functions working with huffman tree nodes
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "huff_tree_node.h"

huff_tree_node* new_node(int character, int frequency, huff_tree_node* left, huff_tree_node* right){
  huff_tree_node* new = malloc(sizeof(huff_tree_node));
  new->ch = character;
  new->freq = frequency;
  new->left = left;
  new->right = right;
  return new;
}

void free_tree(huff_tree_node* root){
  if(root)
  {
    free_tree(root->left);
    free_tree(root->right);
    free(root);
  }

}
