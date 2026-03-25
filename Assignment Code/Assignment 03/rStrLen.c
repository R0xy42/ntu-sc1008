//
//  rStrLen.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.03.15.
//

/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#include <string.h>
int rStrLen(char *s);
int main(void)
{
    char str[80], *p;

    printf("Enter the string: \n");
    fgets(str, 80, stdin);
    p = strchr(str, '\n');
    if (p != NULL) *p = '\0';
    printf("rStrLen(): %d\n", rStrLen(str));
    return 0;
}
int rStrLen(char *s)
{
/*edit*/
/* Write your code here */
    //straightforward！
    //直接先移到右边，然后回来的时候返回1，逐层+1；
    if(*s == '\0'){
        return 0; //最后一个不算长度。
    }
    return rStrLen(s+1) + 1;
    
/*end_edit*/
}
//10s秒了
//竟然只剩下23h50mins了，提交最晚的一次。
