//
//  classifyChar.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.01.31.
//

#include <stdio.h>
int main(void){
    /* start editing */
    
    //单个输入输出
    //scanf读char就行 %c吗？还是%s来着
    //然后ASCII表对照着找范围，if - else if - else
    
    char inchar;
    
    printf("Enter a character:\n");
    scanf("%c",&inchar);
    
    if(inchar>= 65 && inchar <= 90){
        printf("Upper case letter\n");
    }else if(inchar >= 97 && inchar <= 122){
        printf("Lower case letter\n");
    }else if(inchar >= 48 && inchar <= 57){
        printf("Digit\n");
    }else{
        printf("Other character\n");
    }
    
    
    /* end editing */
    return 0;
}
//ok,是没问题的，ASCII码直接google问的AI模式。
//Passed！
