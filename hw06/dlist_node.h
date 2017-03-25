/* dlist_node.h
   Prototypes for functions on a doubly-linked list
*/

#ifndef DLIST_NODE_H_
#define DLIST_NODE_H_

typedef struct dlist_node {
  int data;  // the data stored in this node
  struct dlist_node* next; // pointer to next node
  struct dlist_node* prev; // pointer to previous node
} dlist_node;

// create (i.e., malloc) a new node
dlist_node* new_node(int data, dlist_node* next, dlist_node* prev);

// insert a new node after the given one
// Precondition: Supplied node is not NULL.
void insert_after(dlist_node* n, int data);

// insert a new node before the given one
// Precondition: Supplied node is not NULL.
void insert_before(dlist_node* n, int data);

// delete the given node
// Precondition: Supplied node is not NULL.
void delete_node(dlist_node* n);

// return a pointer to the nth node in the list. If n is
// the length of the list, this returns NULL, but does not error.
// Precondition: the list has at least n nodes
dlist_node* nth_node(dlist_node* head, int n);

// return a pointer to the nth previous node in the list. (That is,
// this uses `prev` pointers, not `next` pointers.) If n is
// the length of the list, this returns NULL, but does not error.
// Precondition: the list has at least n nodes
dlist_node* nth_node_prev(dlist_node* tail, int n);

// free an entire linked list. The list might be empty.
void free_dlist(dlist_node* head);

// create a linked list that stores the same elements as the given array.
// Postcondition: returns the head element
dlist_node* from_array(int n, int a[n]);

// fill in the given array with the elements from the list.
// Returns the number of elements filled in.
// Postcondition: if n is returned, the first n elements of the array
// have been copied from the linked list
int to_array(dlist_node* head, int n, int a[n]);

// gets the length of a list
int length(dlist_node* head);

#endif
