#include <stdlib.h>
#include <stdio.h>
#include "dlist.h"
#include "dlist_node.h"

typedef struct dlist_record {
  dlist_node* head;
  dlist_node* tail;
  int size;

}dlist_record;

dlist dlist_new(){
  dlist d = malloc(sizeof(dlist_record));
  d->head = NULL;
  d->tail = NULL;
  d->size = 0;

  return d;
}

int dlist_size(dlist l){
  return l->size;
}
//actually we can use insert before and insert after here(test later)
void dlist_push(dlist l, int elt){
  if(l->head == NULL)
    l->tail = l->head = new_node(elt, l->tail,l->head);// what is l->head l->head->prev is NULL
  else{
    dlist_node* new = new_node(elt, l->head, l->head->prev);
     l->head->prev = new;
     l->head = new;
  }
  l->size++;
}

void dlist_push_end(dlist l, int elt){
  if(l->tail == NULL)
    l->head = l->tail = new_node(elt, l->tail,l->head);//l->tail is NULL
  else{
    dlist_node* new = new_node(elt, l->tail->next, l->tail);
    l->tail->next = new;
    l->tail = new;
  }
  l->size++;
}

int dlist_pop(dlist l){
  dlist_node* old_head = l->head;
  int val = old_head->data;
  old_head->next->prev = old_head->prev;
  l->head = old_head->next;
  l->size--;

  free(old_head);
  return val;
}

int dlist_peek(dlist l){
  return l->head->data;
}

int dlist_pop_end(dlist l){
  dlist_node* old_tail = l->tail;
  int val = old_tail->data;
  old_tail->prev->next = old_tail->next;
  l->tail = old_tail->prev;
  //printf("our tail of list is  %d \n", l->tail->data);
  l->size--;

  free(old_tail);
  return val;
}

int dlist_peek_end(dlist l){
  return l->tail->data;
}

void dlist_insert(dlist l, int n, int elt){
  int len = l->size;
  dlist_node* target;
  //traverse from head
  if(n == 0){
    dlist_push(l,elt);
    return;
    }
  else if(n <= len/2){
    target = nth_node(l->head,n-1);
    insert_after(target,elt);
  }
  //here tail need to have a special case match
  else if( n == len){
    dlist_push_end(l,elt);
    return;
  }
  //else traverse from tail
  else{
    target = nth_node_prev(l->tail,(len-n));
    insert_after(target,elt);//here , if we add at last position, we gonna have a wrong tail, since we don't update the tail
  }
  l->size++;
}

int dlist_get(dlist l, int n){
  int len = l->size;
  dlist_node* target;
  if(n < len/2){
    target = nth_node(l->head,n);
  }
  //else traverse from tail
  else{
    target = nth_node_prev(l->tail,(len-1-n));
    //printf("size is %d  \n", len);
    // printf("target is %d  \n", target->data);
  }
  return target->data;
}

int dlist_set(dlist l, int n, int new_elt){
  dlist_node* target;
  int len = l->size;
  if(n <= len/2){
    target = nth_node(l->head,n);
  }
  //else traverse from tail
  else{
    target = nth_node_prev(l->tail,(len-1-n));
  }

  int old_val = target->data;
  target->data = new_elt;
  return old_val;
}

int dlist_remove(dlist l, int n){
  dlist_node* target;
  int len = l->size;
  if(n == 0)
    return dlist_pop(l);
  else if( n <= len/2){
    target = nth_node(l->head,n);
  }
  else if( n == (len-1)){
    return dlist_pop_end(l);
  }
  else{
    target = nth_node_prev(l->tail,(len-1-n));
  }

  int elt = target->data;
  delete_node(target);
  l->size--;
  return elt;
}

void dlist_free(dlist l){
  free_dlist(l->head);
  free(l);
}

int main(){
  //so still , the insert and get does not work if n > len/2
  dlist l = dlist_new();
  
  dlist_insert(l, 0, 3);
  dlist_insert(l, 0, 2);
  dlist_insert(l, 0, 1);
  dlist_insert(l, 1, 8);
  dlist_insert(l, 4, 10);
  dlist_insert(l, 1, 6);
  dlist_node* test = l->head;
  // printf(" %d \n", tail->data);
  // printf(" %d \n", dlist_get(l,3));
  printf("we remove %d \n",dlist_set(l,5,22));
  // printf("new tail is %d \n", l->tail->data);
  
  for(int i = 0; i < dlist_size(l); i++){
    printf(" %d \n", dlist_get(l,i));
  }
  
  // dlist_node* test = nth_node_prev(l->tail,1);
    printf("size of list is  %d \n", dlist_size(l));
    
  dlist_free(l);
  return 0;
}
