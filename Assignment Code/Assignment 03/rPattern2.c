//
//  rPattern2.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.03.14.
//

/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
void rPattern2(int height);
int main(void)
{
    int height;

    printf("Enter the height: \n");
    scanf("%d", &height);
    printf("The pattern is: \n");
    rPattern2(height);
    return 0;
}
void rPattern2(int height)
{
/*edit*/
/* Write your code here */
    if(height == 1){
        printf("*\n");
        return;
    }//退出条件，写前面
    
    for (int i=0; i<height; i++) {
        printf("*");
    }
    printf("\n");
    
    rPattern2(height-1);

/*end_edit*/
}
