//
//  temperature.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.01.30.
//

#include <stdio.h>
int main(void){
    
    /* edit start */
    
    float fahrenheit, celsius=0;
//    int flag=0;
    
    while(1){
        printf("Enter the temperature in degree F:\n");
        scanf("%f",&fahrenheit);
//        if(fahrenheit<0){
//            fahrenheit = -fahrenheit;//取正;
//            flag = 1; //说明确实是负的;
//        }
        if (fahrenheit == -1) {//这里float因为精度问题不能直接等于吧……？要用小于某个值？但我是float，要怎么fabs呢？
            break; //其实可以精确表示。整数都可以被精确表示。 除以 2的k次方 的数也可以被精确表示。
        }
        celsius = (5.0/9.0)*(fahrenheit-32);
        printf("Converted degree in C: %.2f\n",celsius);
    }
    
    /* edit end */
    
    return 0;
}


//passed！一次过……算吧？我复制公式的时候：1、忘记用/还是%了，2、忘记了要先加.0 转float再除
//为什么IDE总是把最后一行留出来呢？

//更新260202 - 1605: 把逻辑改了一下，现在可以进行负数转换了。

