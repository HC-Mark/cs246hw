/* conv_hex.c
 *
 * Name:Tianming Xu
 * Desc:a program that convert a number in hexadecimal to an otal number
 */

#include <stdio.h>
#include <ctype.h>


int main(){
  char hex;
  int counter = 0;
  int hex_store[3];
  int oct[ 4 ];
  while((hex = getchar()) != EOF){
    int temp;
    if( hex >= 48 && hex <= 57){
      temp = hex - '0';
    }
    else if( hex >= 65 && hex <= 70){
      temp = hex - 'A' + 10;
    }
    else{
      continue;
    }
    //print("%d\t", temp);

    //store it into an helping array
    int x = counter % 3;
    hex_store[x] = temp;

    //process it into octal
    counter ++;
      //if we process the first 
    if(counter % 3 == 1){
      if(temp >=8){
	oct[0] = temp - 8;
	oct[1] ++;
      }
      else{
	oct[0] = temp;
      }
      char oct1 = oct[0] + '0';
      putchar(oct1);
    }

    //if we process the second
    if(counter % 3 == 2){
      oct[1] += (temp % 4) * 2;
      oct[2] += temp/4;
      char oct2 = oct[1] + '0';
      putchar(oct2);
    }

    //if we process the third one 
    if(counter %3 == 0){
      oct[2] += temp % 2;
      oct[3] += temp / 2;
      char oct3 = oct[2] + '0';
      char oct4 = oct[3] + '0';
      
      int i;
      for(i = 0; i < 4; i++){
	//printf("%d\t", oct[i]);
	oct[i] = 0;
      }
      /*
      printf("\ntest: ");
      for(i = 0; i < 3; i++){
	printf("%d\t", hex_store[i]);
      }
      printf("\n");*/
    }
    temp = 0;
  }
  printf("\n");

  return 0;
}
