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
  int deci_result = 0;
  char hex_result;
  //decimal number processing
  while((num = getchar()) != EOF){   
    if(isdigit(num)){
      int temp = num - '0';
      deci_result = deci_result * 10 + temp;
    }
        
    if(num == '\n'){
      break;
    }
  }
    //printf("temp: %d\n", deci_result);
    int cal;
    while(deci_result != 0){
      cal = deci_result % 16;
      if ( cal >= 0 && cal <  10){
	char temp = cal + '0';
	putchar(temp);
      }
      else{
	if( cal == 10){
	  putchar('A');
	}
	if(cal == 11){
	  putchar('B');
	}
	if( cal == 12){
	  putchar('C');
	}
	if( cal == 13){
	  putchar('D');
	}
	if( cal == 14){
	  putchar('E');
	}
	if( cal == 15){
	  putchar('F');
	}
      }
      deci_result = deci_result / 16 ;
    }
    printf("\n");
    return 0;
}
