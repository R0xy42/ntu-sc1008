//
//  Q2.c
//  LAB
//
//  Created by 邹嘉睿 on 2026.01.31.
//
    /* edit */

/*custom header*/

    /*end_edit*/
#include <stdio.h>
int digitPos1(int num, int digit);
void digitPos2(int num, int digit, int *result);
int main(void){
   int number, digit, result=0;

   printf("Enter the number: \n");
   scanf("%d", &number);
   printf("Enter the digit: \n");
   scanf("%d", &digit);
   printf("digitPos1(): %d\n", digitPos1(number, digit));
   digitPos2(number, digit, &result);
   printf("digitPos2(): %d\n", result);
   return 0;
}

int digitPos1(int num, int digit){
    /*edit*/
   /* Write your code here */
    
    int pos = 0;
    while(num>0){
        pos++; //扫
        if(num % 10 == digit){ //找到
            return pos;
        }
        num /= 10; //删位
    }
    return 0;
    /*end_edit*/
}
void digitPos2(int num, int digit, int *result)
{
    /*edit*/
   /* Write your code here */
    //understanding of lab code
   //use a pos flag (similar to a pointer or an index number.)
   //if left to right, let pos = num_digits first, then pos--;
    int pos=0;
    *result=0;
    do{
        pos++;
        if (num%10 == digit){
            *result = pos;
            break;
        }
        num = num/10;
        //dont forget to eliminate a digit from num after counting it.
    }while(num > 0);
    //this is actually quite smart, it sets *result to 0 at the beginning.
    //so if there is no if condition satisified to update its value;
    //it will return *result with a value of 0;
    
    /*end_edit*/
}


//passed!
