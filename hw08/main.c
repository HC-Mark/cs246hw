#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "forest.h"
//include "huff_tree.h"

#define STRING_LENGTH 100
#define TABLE_LENGTH 256

void print_table(int* arr, int n){
  for(int i = 0; i < n; i++){
    //if(arr[i] != 0)
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
    // print_forest(l);
  }
  
  tree = forest_pop(l);
  return tree;
}
//the initial input of code is 0, and we use that to identify the root
void fillTable(int huffTable[], huff_tree_node* tree, int code){
  int loc = tree->ch;
  if(loc >= 0)
    huffTable[loc] = code;
  else{
    //decimal method
    //fillTable(huffTable,tree->left,code*10+1);//we use 1 stands for binary 0
    //fillTable(huffTable,tree->right,code*10+2);//use 2 stands for binary 1

    //binary method-- char a turns to be zero and have no way to identify from other character which has zero freq.
    code = code << 1;
    int left = code + 0;
    int right = code + 1;
    fillTable(huffTable,tree->left,left);
    fillTable(huffTable,tree->right,right);
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

  //print_forest(f);
   huff_tree_node* new_tree = buildTree(f);
   int huff_Table[TABLE_LENGTH] = {0};
   fillTable(huff_Table,new_tree,0);
   print_table(huff_Table,TABLE_LENGTH);
   //print_huff_tree(new_tree);
  // printf("the total amount of nodes in forest is %d\n", forest_size(f) );
  // printf("the total amount of nodes in array is %d\n", counter);
   //create a new file and store output in it
   FILE* dest;
   dest = fopen("dest.huff","wb");
   fwrite(frequency,sizeof(int),sizeof(frequency)/sizeof(int),dest);//need divide the size of type
   fclose(dest);
   fclose(fp);
  return 0;
}




