/* conv_dec.c
 *
 * Name:Tianming Xu
 * Desc:a program convert decimal to hex number
 */

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int main(){
  char num;
  int counter = 0,deci_result;
  //decimal number processing
  while(true){   
    if(isdigit(num)){
      int temp = num - '0';
      deci_result += temp * (int) pow (10,counter);
      counter++;
    }
    if(num == '\n'){
      break;
    }

    
  }


  printf("%d\n",deci_result);
  return 0;
}
