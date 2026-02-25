//
//  mergeArrays.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.02.20.
//

#include <stdio.h>
#define M 80
int mergeArrays(int a[M], int b[M], int c[M], int n1, int n2);
int main(void)
{
    int a[M],b[M],c[M],i,k=0,n1,n2;
    
    printf("Enter the size of array a: \n");
    scanf("%d", &n1);
    printf("Enter the size of array b: \n");
    scanf("%d", &n2);
    printf("Enter array a[%d]: \n", n1);
    
    for (i=0; i<n1; i++)
        scanf("%d",&a[i]);
    
    printf("Enter array b[%d]: \n", n2);
    
    for (i=0; i<n2; i++)
        scanf("%d",&b[i]);
    
    k=mergeArrays(a,b,c,n1,n2);
    printf("mergeArrays(): \n");
    
    for (i=0;i<k;i++)
        printf("%d ",c[i]);
    return 0;
}

int mergeArrays(int a[M], int b[M], int c[M], int n1, int n2)
{
/* Write code here */
    //a和b都升序排列。然后要合并完c也升序。
    //那先合并呗，写进c里再单独做个排序。bubble sort这样的
    
    int i;
    for (i=0; i<n1+n2; i++) {
        if(i<n1){
            c[i] = a[i];
        }else {
            c[i] = b[i-n1];
        }
//        printf("c[%d] now is: %d\n",i,c[i]); //ok, 这里合并没问题，是下面的bubble sort搞事
    }
    
    //Bubble sort:
    int temp=0;
    int j;
    for (i=0; i<n1+n2; i++) {
        for (j=i+1; j<n1+n2; j++) {
            if(c[i]>=c[j]){
                temp = c[j];
                c[j] = c[i];
                c[i] = temp;
            }
            //swap
        }
    }
    //首先打印出来只有3个数肯定是边界有问题。
    //感觉冒泡没问题啊，这……
    //噢，返回值忘记改了……
    
    return n1+n2;
    //过了！✅
}
