//
//  divide.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.01.30.
//

#include <stdio.h>

int divide1(int m, int n, int *r);
void divide2(int m, int n, int *q, int *r);
int main(void){
   int m, n, q, r;
   
   printf("Enter two numbers (m and n): \n");
   scanf("%d %d", &m, &n);
   q = divide1(m, n, &r);
   printf("divide1(): quotient %d remainder %d\n", q, r);
   divide2(m, n, &q, &r);
   printf("divide2(): quotient %d remainder %d\n", q, r);
   return 0;
}

//Please note that in this question, you are not allowed to use the division (/) and modulus (%) operators.
//？？？这整的我有点疑惑啊，那怎么perform除法？
//alr，除法的本质是被除数不断减去除数对吧，直到减到renewed的被除数小于除数，此时减了几次就相当于 / 符号得到几，然后remainder余数就是剩下的renewed被除数，相当于 %
//哇Xcode好智能！它不会像VSC一样把一行拉的很长，在这里页面只会上下滚动不会水平滚动，超出页面宽度的内容会被自动切到下一行！太爽了w

//divide 1: and the remainder is passed to the caller through the pointer parameter r
//divide 2: the pointer variable q is used to store the quotient which will be returned to the caller, and the remainder is passed to the caller through the pointer parameter r.


int divide1(int m, int n, int *r)
{
    /*edit*/
   /* Write your code here */
    int q1 = 0;
    if(n==0){
        return -1;
    }
    while(m>=n){ // >= ! 否则最后整除会剩一个
        m -= n;
        q1++;
    }
    *r = m;
    return q1;
    /*end_edit*/
}
void divide2(int m, int n, int *q, int *r)
{
    /*edit*/
   /* Write your code here */
    int quotient = 0;
    if(n==0){
        return;
    }
    while(m>=n){
        m -= n;
        quotient++;
    }
    *r = m;
    *q = quotient;
    return;
    /*end_edit*/
}
//passed！
