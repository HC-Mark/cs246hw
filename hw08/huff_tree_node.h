/* huff_tree_node

   prototypes of functions for working with huffman tree
*/
#ifndef HUFF_NODE_H_
#define HUFF_NODE_H_

typedef struct huff_tree_node {
  int ch;
  int freq;

  struct huff_tree_node* left;
  struct huff_tree_node* right;
} huff_tree_node;

//create a new huffman tree node
huff_tree_node* new_node(int character, int frequency, huff_tree_node* left, huff_tree_node* right);

//free all nodes in a huffman tree.
void free_tree(huff_tree_node* root);

//return the size of this tree
int size(huff_tree_node* root);

#endif
