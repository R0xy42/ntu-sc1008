//
//  longWordLength longWordLength longWordLength longWordLength longWordLength.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.02.18.
//

/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#include <string.h>
int longWordLength(char *s);
int main(void)
{
    char str[80], *p;

    printf("Enter a string: \n");
    fgets(str, 80, stdin);
    if (p=strchr(str,'\n')) *p = '\0';
    printf("longWordLength(): %d\n", longWordLength(str));
    return 0;
}
int longWordLength(char *s)
{
/*edit*/
/* Write your code here */
    //也是比较straightforward. for 扫过去 然后计数就可以了，大的就更新。
    //返回值是最长的那个的长度
    //pointer ++;
    
    //草，是word，符号不算！
    //那就得用ASCII码了。
    
    int cnt=0,maxLen=0;
    
    //如果想写的robust一点，如何检查 *s 是不是全是空格呢？
    //initialize maxLen with 0 will work;
    while(*s != '\0'){
        //一个经典的扫字符串的条件语句
        if((*s >= 65 && *s <= 90) || (*s >= 97 && *s <= 122)){
            cnt++;
        }else {
            cnt=0; //逻辑和那个找连续的相同值（platform）一样的。
        }
        
        if(cnt>maxLen){
            maxLen = cnt;
        }
        
        s++; //指针自增
    }
    
    
    return maxLen;
/*end_edit*/
}

//ok 过了！✅

