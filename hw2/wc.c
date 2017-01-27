/* wc.c
 *
 * Name:Tianming Xu
 * Desc:a program that reimplement the utility wc.
 */

#include <stdio.h>
#include <ctype.h>   // for isalpha

int main(){
  char c;
  int character = 0;
  int word = 1;
  int line = 0;

  while((c= getchar()) != EOF){
    
    character ++;
//character always use single quote to quote it, otherwise it turns to be a variable
    if(isspace(c) && c != '\n'){
      word++; //if we have two white spaces here, it will add two words,wrong
    }
    if( c == '\n'){
      line++;
    }
    
  }
  
  printf("char: %d\tword: %d\tline:%d\n", character, word,line);


  return 0;
}
