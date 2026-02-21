//
//  pattern1.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.01.30.
//

#include <stdio.h>
int main(void){
    /* start */
    
    //打印吗…… 在Python就写过这个呢～
    //知道input的话那双层for咯。外层控制行，内层控制每行的具体打印内容（列）
    //是圣诞树形状的。每行 2(n-1)+1 = 2n-1，最后一行就是 2height-1；
    //那前面的行需要 左、右都空height-1个空；
    //诶。好像单层for就可以了啊？既然pattern规律知道的话？
    
    
    int i=0,j=0; // for
    int height;
    
    printf("Enter the height:\n");
    scanf("%d",&height);
    printf("The pattern is:\n");
    
    for(i=1;i<=height;i++){
//        printf(" "*(height-1));
        //可恶不能直接用*来输出多个。有点邪恶。不像py那么方便啊。
        //那还是双层for吧
        for(j=0;j<height-i;j++){
            printf(" ");
        }
        
        for(j=0;j<(2*i-1);j++){
            printf("*");
        }
        
        for(j=0;j<height-i;j++){
            printf(" ");
        }//原来最后问题出在 height - i 上。。。
        //服了。
        printf("\n");
    }
    
    /* end */
    return 0;
}

//Passed!
//有没有简单点的写法呢？
