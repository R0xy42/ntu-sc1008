//
//  rNumDigits.c
//  LAB
//
//  Created by 邹嘉睿 on 2026.03.14.
//

/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int rNumDigits1(int num);
void rNumDigits2(int num, int *result);
int main(void)
{
    int number, result=0;

    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("rNumDigits1(): %d\n", rNumDigits1(number));
    rNumDigits2(number, &result);
    printf("rNumDigits2(): %d\n", result);
    return 0;
}
int rNumDigits1(int num)
{
/*edit*/
/* Write your code here */
    int digits;
    if(num/10 == 0){
        return 1;
    }//end of recursion
    
    digits = rNumDigits1(num/10); //enter deeper lvl
    
    return digits+1;
    
/*end_edit*/
}
void rNumDigits2(int num, int *result)
{
/*edit*/
/* Write your code here */
    if(num/10 == 0){
        *result = 1;
        return;
    }
    
    rNumDigits2(num/10, result);
    //为什么直接传result的地址进去就好：没有涉及修改，让地址逐层传递方便在函数内更新。
    //更新num。
    
    (*result)++; //exit: ++
    
/*end_edit*/
}
