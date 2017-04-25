/* llist.c

   Implementation of an singly linked list sequence
*/

#include <stdlib.h>
#include <stdio.h>
#include "forest.h"

typedef struct forest_record {
  forest_node* head;
  int size;  // number of nodes in the llist
} forest_record;

// return an empty llist. Make sure to call llist_free when you're done
// with it.
forest forest_new()
{
  forest l = malloc(sizeof(forest_record));
  l->head = NULL;
  l->size = 0;
  return l;
}

// returns the number of elements in the llist. Runs in constant time.
int forest_size(forest l)
{
  return l->size;
}

// appends a new element to the beginning of the llist. Runs in constant time.
void forest_push(forest l, huff_tree_node* node)
{
  l->head = forest_node_new(node, l->head);
  l->size++;
}

// removes and returns the first element in the llist. Runs in constant time.
// precondition: there is at least one element in the llist.
huff_tree_node* forest_pop(forest l)
{
  forest_node* old_head = l->head;
  huff_tree_node* val = old_head->data;
  l->head = old_head->next;
  l->size--;
  
  free(old_head);
  return val;
}

// returns the first element in the llist, without changing the llist.
// Runs in constant time.
// precondition: there is at least one element in the llist.
huff_tree_node* forest_peek(forest l)
{
  return l->head->data;
}

// adds a new element into the llist, depending on its frequency and character
void forest_insert(forest l, huff_tree_node* node)
{
  forest_node* tail;
  int size = forest_size(l);
  tail = nth_node(l->head, size-1);
  if(l->head == NULL)
  {
    forest_push(l, node);
    //printf("12\n");
    return;
  }
  else if(l->head->data->freq > node->freq){
    forest_push(l,node);
    //printf("123\n");
    return;
  }
  else if(tail-> data -> freq < node->freq){
    forest_node_insert_after(tail,node);
    //printf("12345\n");
  }
  else
    {
      //if the head freq and node freq is the same
      if(l->head->data->freq == node->freq){
	if(l->head->data->ch > node->ch){
	  forest_push(l,node);
	  return;
	}
      }
      //if only one element exists, without this will cause segmentation fault
      if(tail->data->freq == node->freq){
	if(tail -> data -> freq < node->ch){
	  forest_node_insert_after(tail,node);
	  l->size ++;
	  return;
	}
      }
	int i;
	forest_node* one_before;
	forest_node* one_after;
	for(i = 1; i < size ; i++){
	  //printf("%d\n",i);
	  one_before = nth_node(l->head,i-1);
	  one_after = nth_node(l->head, i);
	  huff_tree_node* temp = one_after -> data;
	  if(temp ->freq < node -> freq)
	    continue;
	  else if(temp ->freq == node->freq){
	    if(temp-> ch > node->ch)
	      break;
	    else
	      continue;
	  }
	  else
	    break;
	}
	forest_node_insert_after(one_before, node);
	//printf("123456\n");
    }
      l->size++;
    
}

// retrieves the nth element of the llist. Takes O(n) steps.
// precondition: the list has at least (n+1) elements
huff_tree_node* forest_get(forest l, int n)
{
  return nth_node(l->head, n)->data;
}

//get the head of the forest
forest_node* forest_head(forest l)
{
  return l->head;
}

// frees an llist. Takes O(size(l)) steps.
void forest_free(forest l)
{
  forest_node_free(l->head);
  free(l);
}
