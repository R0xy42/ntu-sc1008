//
//  rSquare.c
//  LAB
//
//  Created by 邹嘉睿 on 2026.03.14.
//

/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int rSquare1(int num);
void rSquare2(int num, int *result);
int main(void)
{
    int number, result=0;

    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("rSquare1(): %d\n", rSquare1(number));
    rSquare2(number, &result);
    printf("rSquare2(): %d\n", result);
    return 0;
}
int rSquare1(int num)
{
/*edit*/
/* Write your code here */
    // num times
    // from 1+3+5+7+...+(2n-1)+...
    // the n-th term = 2n-1, also = (n-1)-th term +2 ;
    // num-1 until 1, and then adding from 1 , +2 +2 +2...
    
    if(num == 1){
        return 1;
    }
    
    return rSquare1(num-1) + 2*num - 1;
    

/*end_edit*/
}
void rSquare2(int num, int *result)
{
/*edit*/
/* Write your code here */
    
    if(num == 1){
        *result = 1;
        return;
    }
    
    rSquare2(num-1, result);
    
    *result += 2*num - 1;

/*end_edit*/
}

