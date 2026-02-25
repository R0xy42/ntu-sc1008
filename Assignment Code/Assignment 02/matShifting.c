//
//  matShifting.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.02.20.
//

#include <stdio.h>
#define M 10

void matShifting(int a[M][M], int b[M][M], int n);
int main(void)
{
    int a[M][M], b[M][M];
    int n,i,j;
    printf("Enter array (nxn) size (n<=10): \n");
    scanf("%d",&n);
    
    for (i=0; i<n; i++) {
        printf("Enter row %d: \n", i);
        for (j=0; j<n; j++)
            scanf("%d",&a[i][j]);
    }
    
    matShifting(a,b,n);
    
    printf("Array b: \n");
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }
return 0;
}
void matShifting(int a[M][M], int b[M][M], int n)
{
/* Write your code here */
    
    //感觉也是比较直接的一题。只shift一个的话
    //我其实想自己写一个shift指定行数的。这个会比较有意思一点：——先计算出shift几次会回来，就是col次，然后再把指定的行数归一化（mol，用%取余数）
    //归一化进 0 ～ col-1 这个区间内。就好办了。思路是一次移动一个，直到到达指定位置为止。
    //或者有没有更快的？直接把对应的两行交换？这样的复杂度是多少？
    
    //先写一行的实现吧。
    
    int colA=0,colB=1;
    int row;
    int cnt=1;
    
    while (1) {
        //swap 1 col
        for (row=0; row<n; row++) {
            if(colB==n){
                //colA==n-1,boundary, write to colB==0;
                b[row][0] = a[row][colA];
            }else {b[row][colB] = a[row][colA];}
            //一个变量col没法表示两个位置。
        }
        if(cnt==n){
            break;
        }
        colB++;
        colA++;
        cnt++;
        //整体推移一行需要进行 n 次移动。
        //如果推移指定行，比如 n-1 呢
        //那就需要 n-1 次移动。if{cnt == n*(n-1)} break;
        //negative，不是这么简单的。但是今晚一时想不清怎么解出那个mod公式了，先睡吧。
        //以上。
    }
    
}

//2026.2.21，12:13am
//可以了，「一个变量没法表示两个位置啊」


