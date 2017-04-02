#include <stdlib.h>
#include "dlist_node.h"
#include <stdio.h>

dlist_node* new_node(int data, dlist_node* next, dlist_node* prev){
  dlist_node* n = malloc(sizeof(dlist_node));
  n->data = data;
  n->next = next;
  n->prev = prev;
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
  if(n->prev != NULL){
    dlist_node* new = new_node(data, n, n->prev);
    n->prev->next = new;
    n->prev = new;
  }
  else{
    n->prev = new_node(data, n, n->prev);
  }
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
  for(; n>0; n--, head = head->next)
    ;
  return head;
}

dlist_node* nth_node_prev(dlist_node* tail, int n){
  for(; n > 0; n--, tail = tail -> prev)
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
  int i;
  for(i =0; i < n && head; i++, head = head->next){
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

//test if dlist_node, succeed!
/*
int main(){
  dlist_node* head = NULL;
  dlist_node* tail = NULL;
  int xs[] = { 1, 4, 8, 3, 5 };
  int len = sizeof(xs)/sizeof(xs[0]);
  // dlist_node* new_head = new_node(xs[0], head,tail);
  dlist_node* new_tail = new_node(xs[4],head,tail);
  

  for(int i = len-1; i >= 1; i--)
  {
    insert_after(new_head,xs[i]);
  }

  
  for(int i = 0; i < len-1; i++)
  {
    insert_before(new_tail,xs[i]);
  }
  
  //delete_node(new->next->next);
  //dlist_node* new_head = from_array(len,xs);
  //printf(" %d \n", nth_node(new_head,4)->data);
  
  for(int i = 0; i < len; i++, new_head = new_head->next){
     printf(" %d ", new_head->data);
   }
  
  //printf("length of new_head = %d\n", length(new_head));
  //printf(" %d \n", nth_node_prev(new_tail,4)->data);
  // free(new_head);
  // free(clear);
  // printf(" %d \n", new_tail->data);
  // printf(" %d \n", new_head->data);
  //printf(" %d ", nth_node(new_head,0)->data);
  //printf(" %d ", head->data);
  
}
*/

