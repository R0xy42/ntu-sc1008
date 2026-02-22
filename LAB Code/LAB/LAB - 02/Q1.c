//
//  main.c
//  LAB
//
//  Created by 邹嘉睿 on 2026.01.29.
//

#include <stdio.h>

int numDigits1(int num);
void numDigits2(int num, int *result);
int main(void)
{
    int number, result=0;
    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("numDigits1(): %d\n", numDigits1(number));
    numDigits2(number, &result);
    printf("numDigits2(): %d\n", result);
    return 0;
}

int numDigits1(int num){
    int count = 0;
    do {
        count++;
        num = num/10;
    } while (num > 0);
    return count;
}
void numDigits2(int num, int *result){
    /* Write your code here */
    
    *result = numDigits1(num);
    
}

