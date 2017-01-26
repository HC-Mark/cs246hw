/* cat.c
 *
 * Name:Tianming Xu
 * Desc:a program repeats what user types into the terminal
 */

#include <stdio.h>
#include <stdbool.h>

int main(){
  char c;
  
  while((c = getchar()) != EOF){

      printf("%c",c);
      
  }
  
  return 0;
}
