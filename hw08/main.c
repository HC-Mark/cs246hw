#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "forest.h"

#define STRING_LENGTH 100
#define TABLE_LENGTH 128

void print_table(int* arr, int n){
  for(int i = 0; i < n; i++){
    if(arr[i] != 0)
      printf("%c has frequency: %d\n",i,arr[i]);
  }
}

void print_forest(forest l){
  forest_node* head = forest_head(l);
  if(head == NULL)
    printf("invalid forest, sad\n");
  else{
    forest_node* f;
    for(f = head;f != NULL; f = f -> next){
      printf("%c has frequency: %d\n", f->data->ch, f->data->freq);
    }
  }

}

int main(int argc, char** argv){
  FILE* fp;
  char target[STRING_LENGTH];
  int frequency[TABLE_LENGTH] = {};
  int ch;//variable that stores input characters
  if(argc < 2){
    printf("at least give me one file to do the job!\n");
    exit(EXIT_FAILURE);
  }
  strcpy(target, argv[1]);
  fp = fopen(target, "r");
  while ((ch = getc(fp)) != EOF)
    frequency[ch]++;
  
  //print_table(frequency,TABLE_LENGTH);
  huff_tree_node* test[TABLE_LENGTH];
  int counter = 0;//know where each node should go in this array
  for(int i = 0; i < TABLE_LENGTH; i++){
    if(frequency[i] != 0)
      test[counter++] = new_node(i,frequency[i],NULL,NULL);
    //else
    //test[counter++] = NULL;
  }
  
  for(int i = 0; i < counter; i++){
    if(test[i]){
      int ch = test[i] -> ch;
      int freq = test[i] -> freq;
      //printf("this node contains %c with frequency of %d\n",ch,freq);
    }
  }

  forest f = forest_new();
  for(int i = 0; i < counter; i++){
    forest_insert(f,test[i]);
  }

  print_forest(f);
  // printf("the total amount of nodes in forest is %d\n", forest_size(f) );
  // printf("the total amount of nodes in array is %d\n", counter);
  return 0;
}




