#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "forest.h"
//include "huff_tree.h"

#define STRING_LENGTH 100
#define TABLE_LENGTH 256

typedef struct table_elem{
  int num_bits;//how many bits this character will take
  int code;//the actually code encoded by the huff_tree algorithms
}table_elem;

void print_table(int* arr, int n){
  for(int i = 0; i < n; i++){
    if(arr[i] != 0)
      printf("%c has frequency: %d\n",i,arr[i]);
  }
}

void print_huff_table(table_elem** arr, int n){
  for(int i = 0; i < n; i++){
    if(arr[i]){
      int code = arr[i]-> code;
      int num_bits = arr[i] -> num_bits;
      printf("the huff code of %c is %d and it has %d bits\n",i, code, num_bits);
    }
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

void print_huff_tree(huff_tree_node* root){
  if(root){
    int result = root -> ch;
    if(result < 0){
      printf("This internal node has id %d and it has freq %d\n",result,root->freq);
      huff_tree_node* left = root -> left;
      huff_tree_node* right = root -> right;
      if(left->ch < 0)
	printf("its left child is internal which has id %d\n", left->ch);
      else
	printf("its left child is a char %c\n",left->ch);
      if(right->ch< 0)
	printf("its right child is internal which has id %d\n", right->ch);
      else
	printf("its right child is a char %c\n",right->ch);
    }
    else
      printf("This character is %c and its freq is %d\n",result, root->freq);

    print_huff_tree(root->left);
    print_huff_tree(root->right);
  }
}

huff_tree_node* buildTree(forest l){
  huff_tree_node* tree;
  int size = forest_size(l);
  int counter = -1;
  while( size > 1){
    // printf("tell me the size %d\n",size);
    huff_tree_node* smallest = forest_pop(l);
    huff_tree_node* smallTwo = forest_pop(l);
    int new_freq = smallest->freq + smallTwo -> freq;
    huff_tree_node* internal = new_node(counter, new_freq,smallest,smallTwo);
    forest_insert(l,internal);
    counter--;
    size = forest_size(l);
  }
  
  tree = forest_pop(l);
  return tree;
}

//the initial input of code is 0, and we use that to identify the root
/*
void fillTable1(int huffTable[], huff_tree_node* tree, int code){
  int loc = tree->ch;
  if(loc >= 0)
    huffTable[loc] = code;
  else{
    //decimal method
    printf("go left\n");
    fillTable1(huffTable,tree->left,code*10+1);//we use 1 stands for binary 0
    printf("go right\n");
    fillTable1(huffTable,tree->right,code*10+2);//use 2 stands for binary 1

    //binary method-- char a turns to be zero and have no way to identify from other character which has zero freq.
    //code = code << 1;
    // int left = code + 0;
    // int right = code + 1;
    // fillTable(huffTable,tree->left,left);
    // fillTable(huffTable,tree->right,right);
  }

}
*/
//fill in the huff_table
void fillTable(table_elem* huffTable[], huff_tree_node* tree, int code,int counter){
  if(tree){
    int loc = tree->ch;
    if(loc >= 0){
      printf("store %c in table\n", loc);
      table_elem* store;
      store->code = code;
      store->num_bits = counter;
      huffTable[loc] = store;
    }
    else{
      counter ++;      
      //binary method-- char a turns to be zero and have no way to identify from other character which has zero freq.
      //we need a new data structure to store the bits infor
      code = code << 1;
      int left = code + 0;
      int right = code + 1;
      printf("go left\n");
      fillTable(huffTable,tree->left,left,counter);
      printf("go right\n");
      if(tree->right)
	printf("let me know what is that %d\n", tree->right);
      else
	printf("It is NULL\n");
      fillTable(huffTable,tree->right,right,counter);
      
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
  
  forest f = forest_new();
  for(int i = 0; i < counter; i++){
    forest_insert(f,test[i]);
  }

  //print_forest(f);
  huff_tree_node* new_tree = buildTree(f);
  print_huff_tree(new_tree);
  table_elem* huff_Table[TABLE_LENGTH] = {};

  //test
  //int huff_Table[TABLE_LENGTH] = {};
  //fillTable1(huff_Table,new_tree,0);
  //print_table(huff_Table,256);
  
  // fillTable(huff_Table,new_tree,0,0);
  //print_huff_table(huff_Table,TABLE_LENGTH);
  // printf("the total amount of nodes in forest is %d\n", forest_size(f) );
  // printf("the total amount of nodes in array is %d\n", counter);
   //put the frequency table in the dest file
   FILE* dest;
   dest = fopen("dest.huff","wb");
   fwrite(frequency,sizeof(int),sizeof(frequency)/sizeof(int),dest);//need divide the size of type
   fclose(dest);
   fclose(fp);
  return 0;
}




