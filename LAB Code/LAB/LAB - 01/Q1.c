//
//  Q1.c
//  LAB
//
//  Created by 邹嘉睿 on 2026.01.29.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    // 吗的，神秘APAS要求输入的字符串严格匹配，我自己写反而挂了
    // 比如“enter -1 to exit”这种，没有出现在作业上的语句就不要写了。
    
    char ID[100];
    int mark;

    while(1){
        printf("please enter student ID, or enter -1 to exit:\n");
        scanf("%99s",ID); //limit the length, save one for the last \0
        if(strcmp(ID,"-1") == 0){
            printf("Program has ended due to -1 input!\n");
            break;
        }
        printf("please enter student mark:\n");
        scanf("%d",&mark);
        //C里面的switch case不能写条件判断式。所以该怎么选择呢？写if吗？
        //大概是吧。然后 else 就显示成绩输入错误（不在0～100）
        if(mark>=75 && mark <=100){
            printf("Grade = A\n");
        }else if(mark >= 65 && mark <= 74){
            printf("Grade = B\n");
        }else if(mark >= 55 && mark <= 64){
            printf("Grade = C\n");
        }else if (mark >= 45 && mark <=54){
            printf("Grade = D\n");
        }else if (mark >= 0 && mark <=44){
            printf("Grade = F\n");
        }else {
            printf("The mark you just entered is invalid!\n");
        }
    }
    return 0;
}
