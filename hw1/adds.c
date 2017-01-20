/* adds.c
 *
 * Name:Tianming Xu
 * Desc:a simple c program that output the sum of
 *      a series of integer input given by user.
 */

#include <stdio.h>

int main(){
  //initialize the input variable and sum variable
  int input, sum = 0;

  //a do-while loop to keep your program running until user enter 0
  do{
    //get a number
    printf("Enter a number here: ");
    scanf("%d", &input);

    sum = sum + input;
  }while(input !=0);

  printf("Sum: %d\n", sum);

  return 0;


}
