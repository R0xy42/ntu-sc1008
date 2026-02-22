//
//  main.c
//  LAB
//
//  Created by 邹嘉睿 on 2026.01.22.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
/*  Q1  */
//
//    char ID[100];
//    int mark;
//    
//    while(1){
//        printf("please enter student ID, or enter -1 to exit:\n");
//        scanf("%99s",ID); //limit the length, save one for the last \0
//        if(strcmp(ID,"-1") == 0){
//            printf("Program has ended due to -1 input!\n");
//            break;
//        }
//        printf("please enter student mark:\n");
//        scanf("%d",&mark);
//        //C里面的switch case不能写条件判断式。所以该怎么选择呢？写if吗？
//        //大概是吧。然后 else 就显示成绩输入错误（不在0～100）
//        if(mark>=75 && mark <=100){
//            printf("Grade = A\n");
//        }else if(mark >= 65 && mark <= 74){
//            printf("Grade = B\n");
//        }else if(mark >= 55 && mark <= 64){
//            printf("Grade = C\n");
//        }else if (mark >= 45 && mark <=54){
//            printf("Grade = D\n");
//        }else if (mark >= 0 && mark <=44){
//            printf("Grade = F\n");
//        }else {
//            printf("The mark you just entered is invalid!\n");
//        }
//    }

    
/* Q2 */
    //行数可以用全局变量记住
    //空格隔开。
    //怎么持续读呢？—— 或者一次读一个然后-1截止？那for套while咯
    //内部统计读到的个数
    int line,input;
    //int flag = 1; //本来这句是打算在while里用标志位的。发现可以直接写for里。
    printf("please enter number of lines:\n");
    scanf("%d",&line);
    
    for(int i=0; i < line; i++){
        float sum = 0; //被坑了。这里sum不应该是全局的。应该是local sum。每行重置。否则影响后续计算。
        //sum, num, avg都是。
        float avg=0,num=0;
        printf("please enter line %d, enter -1 to exit:\n",i+1);
        while(1){
//            flag = 0; //标志位置0，防止后续打印
            scanf("%d",&input);
            if(input < 0 && input != -1){
                printf("invalid input! Try another value!\n");
                continue; //C里面也有continue关键字啊。
            }
            if(input == -1){
                if(num == 0){
                    printf("No valid numbers in this line.\n"); //检查恶意输入-1
                }else{
                    avg = sum / num;
                    printf("Average = %.2f\n",avg);
                }
                break;
            }else num++; //个数
            sum += input; //总和
//            if(i==2){
//                printf("newest input = %d\n",input);
//                printf("sum = %f\n",sum);
//            }
        }
//        flag = 1;
        //每次过完一行，新的一行的一句要打印。
    }
    //得自己设计一点test sample吧……
    return EXIT_SUCCESS;
}
