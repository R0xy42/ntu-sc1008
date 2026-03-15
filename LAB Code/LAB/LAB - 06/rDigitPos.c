//
//  rDigitPos.c
//  LAB
//
//  Created by 邹嘉睿 on 2026.03.14.
//

/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int rDigitPos1(int num, int digit);
void rDigitPos2(int num, int digit, int *pos);
int main(void)
{
    int number, digit, result=0;

    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("Enter the digit: \n");
    scanf("%d", &digit);
    printf("rDigitPos1(): %d\n", rDigitPos1(number, digit));
    rDigitPos2(number, digit, &result);
    printf("rDigitPos2(): %d\n", result);
    return 0;
}
int rDigitPos1(int num, int digit)
{
/*edit*/
/* Write your code here */
    //use recursion to deduct digits.
    //每次都检查（调用） 少一位的num？然后pos增加一位？
    //recrusive 条件：当前没有检测到
    //结束条件：检测到了，返回pos值。
    //如果这层（第一层）找到了，：直接return1.
    //没找到：去上层找。return pos+1 也就是从右往左找，但是从左往右加回去。
    if(num == 0) return 0; //没找到
    if(num %10 == digit) return 1; //找到了
    
    int pos = rDigitPos1(num/10, digit);
    
    if(pos == 0){
        return 0;
    }
    
    return pos+1;//退出的时候不断pos+1
/*end_edit*/
}
void rDigitPos2(int num, int digit, int *pos)
{
/*edit*/
/* Write your code here */
    if(num == 0){
        *pos = 0;
        return;
    }
    
    if(num%10 == digit){
        *pos = 1;
        return;
    }
    
    rDigitPos2(num/10, digit, pos);
    
    if(*pos != 0){
        (*pos)++;
        //找到了，逐层退出的时候把 pos 加上。相当于“还原。”
    }
    

/*end_edit*/
}
