//
//  main.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.01.29.
//

/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int reverseDigits(int num);
int main(void){
    
    int num, result=999;
    printf("Enter a number: \n");
    scanf("%d", &num);
    printf("reverseDigits(): %d\n", reverseDigits(num));
    return 0;
}

int reverseDigits(int num){
/*edit*/
/* Write your code here */
    //可以用取余数的方法，类似Lab 2 的奇偶判断，然后再*power 这样把它们累加起来
    //或者用char？转字符串然后反着打印？
    
    //先用第一种方式实现一下吧：
    
    //怎么知道是几位的呢？ —— 循环 /10
    
    int reversed_num=0;

//    long long x; //防止-32768溢出
    int x,cnt = 0;
    int power = 1;
    //感觉跟加法相关的最好初始化为0，而跟乘法相关的最好初始化为1；
    
    x = num;
    if(x<0){x=-x;} //负数的负号不计入位数，翻正。
    if(x==0){cnt = 1;} //0 --- 1位
    while(x>0){ //这里>=0就死循环了
        x /= 10;
        cnt++;
    }
//    printf("cnt = %d\n",cnt);
    //得到位数cnt；
    
    //先cal power最后会到多少
    int k;
    for(k=1;k<=cnt-1;k++){ //1 ~ cnt-1, (cnt-1) in tot;
        power *= 10;
    }
    
    //现在希望每次取1位，从右往左因为是用的除法。然后乘以power来还原。 // % instead of /
    int i,r;
    for(i=0;i<cnt;i++){
        r = num % 10;
        num /= 10;
        reversed_num += r * power;
        power /= 10;
    }
    
    return reversed_num;
/*end_edit*/
}
