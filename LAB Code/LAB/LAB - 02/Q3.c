//
//  Q3.c
//  LAB
//
//  Created by 邹嘉睿 on 2026.01.31.
//

#include <stdio.h>
int square1(int num);
void square2(int num, int *result);
int main(void){
    int number, result=0;
    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("square1(): %d\n", square1(number));
    square2(number, &result);
    printf("square2(): %d\n", result);
    return 0;
}

int square1(int num){
    /*edit*/
    /* Write your code here */
    int sum = 0;
    int i;
    for(i=0;i<num;i++){
        sum += 2*i + 1;
    }
    return sum;

    /*end_edit*/
}

void square2(int num, int *result){
    /*edit*/
    /* Write your code here */

    *result = square1(num);
    /*end_edit*/
}

//passed！
