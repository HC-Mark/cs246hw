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
  oct[0] = 0;
  oct[1] = 0;
  oct[2] = 0;
  oct[3] = 0;
  while(((hex = getchar()) != EOF) || (counter % 3 != 0)){
    // printf("start of iteration\n");
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
    //printf("%d\n", temp);
    counter ++;

    //store it into an helping array
    int x = counter % 3;
    hex_store[x] = temp;

    //process it into octal
      //if we process the first 
    if(counter % 3 == 1){
      if(temp >=8){
	oct[0] = temp - 8;
	//	printf("oct[1] init: %d\n", oct[1]);
	oct[1] ++;
      }
      else{
	oct[0] = temp;
      }
    }
    //if we process the second
    if(counter % 3 == 2){
      // printf("before %d\n", oct[1]);
      oct[1] += (temp % 4) * 2;
      // printf("after %d\n", oct[1]);
      oct[2] += temp/4;
    }

    //if we process the third one 
    if(counter %3 == 0){
      oct[2] += temp % 2;
      oct[3] += temp / 2;
      /*
      int i;
     for(i = 0; i < 4; i++){
	printf("%d\t", oct[i]);
	oct[i] = 0;
      }
      
      printf("\ntest: ");
      for(i = 0; i < 3; i++){
	printf("%d\t", hex_store[i]);
      }
      printf("\n");*/
      }
    	     
    if(hex == EOF){
      // printf("%d\n",oct[0]);
      	char oct1 = oct[0] + '0';
      	putchar(oct1);
      	
      	if(oct[1] == 0 && oct[2] == 0 && oct[3] == 0){
		break;
	}else{
	  // printf("%d\n", oct[1]);
	       char oct2 = oct[1] + '0';
	       putchar(oct2);
	}
	
	if(oct[2] == 0 && oct[3] == 0){
		break;
	}else{
	  // printf("%d\n",oct[2]);
	  char oct3 = oct[2] + '0';
	  	putchar(oct3);
	}
	    
	if(oct[3] == 0){
		break;
	}else{
	  // printf("%d\n",oct[3]);
	  	char oct4 = oct[3] + '0';
	  	putchar(oct4);
	}
	    
      }
      else if (counter % 3 == 0){
	//printf("printing everything\n");
	//printf("%d %d %d %d ", oct[0],oct[1],oct[2],oct[3]);
	//int i;
	//for( i = 0;i < 4; i++){
	//  oct[i] =0;
	//}
	
      	char oct1 = oct[0] + '0';
      	putchar(oct1);
      	oct[0] = 0;    
      	char oct2 = oct[1] + '0';
      	putchar(oct2);
      	oct[1] = 0;  
      	char oct3 = oct[2] + '0';
      	putchar(oct3);
      	oct[2] = 0;   
      	char oct4 = oct[3] + '0';
      	putchar(oct4);
      	oct[3] = 0;
        
	}
    
    temp = 0;
  }
  printf("\n");

  return 0;
}
