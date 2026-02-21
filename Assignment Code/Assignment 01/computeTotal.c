//
//  computeTotal.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.01.29.
//

#include <stdio.h>
int main(void){
    /* code start */
    
    //第一行容易
    //关键是第二行如何先读一个再读后续的
    //用while吗。直到读数 = 预期个数？
    //然后第二行累加就可以了。
    //while 套 for，分别干啥想清楚。
    
    int line_num, cnt=0, element_cnt=0; //line_num; line number input
    int i;
    int element,sum=0;
    //cnt: line number actual count;
    //element_cnt: element number count;
    //element: read element
    printf("Enter number of lines: \n");
    scanf("%d",&line_num);
    
    while(cnt<line_num){
        cnt++;
        printf("Enter line %d:\n",cnt);
        scanf("%d",&element_cnt);
        for(i=0; i<element_cnt;i++){
            scanf("%d",&element);
            sum += element;
        }
        printf("Total: %d\n",sum);
        sum = 0; //重置。
    }
    
    /* code end */
    return 0;
}

//爽！😊 一遍过！
//发现APAS 系统上不支持中文输入，所以如果要在APAS系统上compile的话注释就只能写英文。这个不太方便。

