//
//  extEvenDigits.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.01.31.
//

#include <stdio.h>
#define INIT_VALUE 999

int extEvenDigits1(int num);
void extEvenDigits2(int num, int *result);

int main(void){
    int number, result = INIT_VALUE;
    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("extEvenDigits1(): %d\n", extEvenDigits1(number));
    extEvenDigits2(number, &result);
    printf("extEvenDigits2(): %d\n", result);
    return 0;
}

//感觉可以用2调1，这样就只需要写一遍了w
//那取出偶数也很简单，就是TUT上讲过的直接 %10 取数字，然后再 %2 判断是不是偶数，再每次 /10 删除number位数。
//怎么拼接？
//其实不用管反转的话甚至不需要用i记住走了几位，直接后来的一位乘10添加上就行了，然后位数 *= 10；给个power 变量。
//for还是while：while吧，不知道输入的数字的长度，然后设置读到最后一位（首位）的时候也就是 num<10 时停下来。
//emm不行，这样不会读最后一位，得 num==0，写<=

int extEvenDigits1(int num){
    /* Write your code here */
    int ans=0;
    int power = 1;
    int remainder;
    
    while(1){
        if(num<=0){
            break;
        }
        remainder = num % 10;
        if(remainder % 2 == 0){
            //偶数
            ans += remainder * power;
            power *= 10; //进位只发生在有了偶数之后，而不是像反转一样每次都进
        }
        num /= 10; //这个要每次都删。
    }
    
    if(ans == 0){
        return -1;
    }
    
    return ans;
}
void extEvenDigits2(int num, int *result){
    /* Write your code here */
    *result = extEvenDigits1(num);
    return;
    //我是懒鬼，这多方便啊。
}
//0也可以正常检测的！
//😋爽！20mins 然后一次过。幸福☺️
