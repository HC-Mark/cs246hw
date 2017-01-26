/* scream.c
 *
 * Name:Tianming Xu
 * Desc:a program that did exactly the same as shout.c but we use bit-flicking 
        operation to get this.
 */

#include <stdio.h>
#include <ctype.h>   // for isalpha

int main(){
  char c;
  int helper = 32;
  while((c = getchar()) != EOF){
    if(isalpha(c)){
      c = c ^ helper;
    }
    putchar(c);

  }

  return 0;
}
