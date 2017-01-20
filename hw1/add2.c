/* add2.c
 *
 * Name:Tianming Xu(Mark)
 * Desc:a simple c program that user inputs two number and return its sum.
 */

#include <stdio.h>

int main(){
  //initialize the int variable we need
  int first, second;

  //get the first number
  printf("Enter a number here: ");
  scanf("%d", &first);

  //get the second number
  printf("enter a number here: ");
  scanf("%d", &second);

  //print out the sum of these two number we get
  printf("the sum is: %d\n", first+second);//c can do some simple calculation

}
