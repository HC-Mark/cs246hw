/* shout.c
 *
 * Name:Tianming Xu
 * Desc:a program that output the user input in uppercase
 */

#include <stdio.h>
#include <ctype.h>   // for isalpha

int main(){
  char c;

  while((c = getchar()) != EOF){
    if(isalpha(c)){
      c = c - 'a' + 'A';
    }
    putchar(c);
  }
  return 0;

}
