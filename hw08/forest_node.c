/* forest_node.c

   A singly-linked list implementation
*/

#include <stdlib.h>

#include "forest_node.h"

// create (i.e., malloc) a new node
forest_node* forest_node_new(huff_tree_node* data, forest_node* next)
{
  forest_node* n = malloc(sizeof(forest_node));
  n->data = data;
  n->next = next;
  return n;
}

// insert a new node after the given one
// Precondition: Supplied node is not NULL.
void forest_node_insert_after(forest_node* n, huff_tree_node* data)
{
  n->next = forest_node_new(data, n->next);
}

// find the node in the nth location
forest_node* nth_node(forest_node* head, int n)
{
  for( ; n > 0; n--, head = head->next)
    ;
  return head;
}

// free an entire linked list. The list might be empty.
void forest_node_free(forest_node* head)
{
  forest_node* cur = head;
  while(cur)
  {
    head = cur;
    cur = cur->next;
    free(head);
  }
}
