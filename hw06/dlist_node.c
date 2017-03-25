#include <stdlib.h>
#include "dlist_node.h"

dlist_node* new_node(int data, dlist_node* next, dlist_node* prev){
  dlist_node* n = melloc(sizeof(dlist_node));
  n->data = data;
  d->next = next;
  d->prev = prev;
  return n;
}

void insert_after(dlist_node* n, int data){
  if(n->next != NULL){
    dlist_node* new = new_node(data, n->next,n);
    n->next->prev = new;
    n->next = new;
  }
  else{
    n->next = new_node(data, n->next,n);//the same as the method in single linked list
  }
}

void insert_before(dlist_node* n, int data){
  dlist_node* new = new_node(data, n, n->prev);
  n->prev->next = new;
  n->prev = new;
}

void delete_node(dlist_node* n){
  //if the node is the head
  if( n -> prev == NULL){
    n-> next-> prev = n-> prev;
    free(n);
  }
  //if the node is the tail
  else if( n -> next == NULL){
    n -> prev -> next = n -> next;
    free(n);
  }else{
  dlist_node* adv = n->next;
  dlist_node* prev = n->prev;

  prev->next = adv;
  adv->prev = prev;

  free(n);
  }
}

dlist_node* nth_node(dlist_node* head, int n){
  int i;
  for( i = 0; i < n; i++, head = head->next)
    ;
  return head;
}

dlist_node* nth_node_prev(dlist_node* tail, int n){
  int i;
  for( int i = 0; i < n; i++, tail = tail -> prev)
    ;
  return tail;
}

void free_dlist(dlist_node* head){
  dlist_node* cur = head;

  while(cur){
    head = cur;
    cur = cur->next;
    free(head);
  }
}

dlist_node* from_array(int n, int a[n]){
  dlist_node* tail = new_node(a[n-1],NULL,NULL);
  for(int i = 0; i < n-1; i++){
    insert_before(tail, a[i]);
  }

  dlist_node* head = nth_node_prev(tail, n-1);
  
  return head;
}

int to_array(dlist_node* head, int n, int a[n]){
  for(int i =0; i < n && head; i++, head = head->next){
    a[i] = head->data;
  }
  return i;
}
int length(dlist_node* head){
  int len = 0;
  while(head){
    len++;
    head = head->next;
  }
  return len;
}

int main(){
  return 0;
}

