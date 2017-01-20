/* calc.c
 *
 * Name:Tianming Xu
 * Desc:a not so simple c program that works as a simple calculator.
 */

#include <stdio.h>
int main(){
  /*
  //test for %c
  char test;
  printf("enter a character here: ");
  scanf("%c", &test);

  printf("character: %c \n", test);

  printf("test:%d \n", test == '*');

  return 0;
  */
  //initialize operation and number as variable
  char op_input;
  int num1, num2, result;
  
  while(42){
      printf("Enter an operation: ");
      scanf(" %c", &op_input);
      if(op_input == '0'){
	break;
      }

      	//get two inputs
	printf("Enter a number: ");
	scanf("%d", &num1);

	printf("Enter a number: ");
	scanf("%d", &num2);
      //if the operation we get is '+'
      if(op_input == '+'){
	
	result = num1 + num2;
	printf("%d + %d = %d \n", num1, num2, result);
	
      }
      //if the operation we get is '-'
      else if(op_input == '-'){
	
	result = num1 - num2;
	printf("%d - %d = %d \n", num1, num2, result);
	
      }

      //if the operation we get is '*'
      else if(op_input == '*'){
	
	result = num1 * num2;
	printf("%d * %d = %d \n", num1, num2, result);
	
      }
      //if the operation we get is '/'
      else if(op_input == '/'){
	if(num2 == 0){
	  printf("invalid calculation, please do not divide by 0.\n");
	  continue;
	}
	result = num1 / num2;
	printf("%d / %d = %d \n", num1, num2, result);
	
      }
      else{
	
	printf("wrong type of input, please type '+','-','*','/',or'0' to exit program. ");
	
      }
	
  
  }



  printf("good-bye!\n");
  return 0;
}
