//
//  stringrChr.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.02.18.
//

/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#include <string.h>
char *stringrChr(char *s, char ch);
int main(void)
{
    char s[80], c, *p;
    char *temp=NULL;

    printf("Enter a string: \n");
    fgets(s, 80, stdin);
    if (p=strchr(s,'\n')) *p = '\0';
    printf("Enter a char: \n");
    scanf("%c", &c);
    temp = stringrChr(s, c);
    if (temp!=NULL)
      printf("stringrChr(): %s\n", temp);
    else
      printf("stringrChr(): null string\n");
    return 0;
}

char *stringrChr(char *s, char ch)
{
    /*edit*/
    /* Write your code here */
    //大致思路是从右往左扫，如果扫到了就打印且说明是最后一个。（比从左往右扫好）
    //如果没扫到就是没有。
    
    char *p = s;
    char *l = s;
    
    
    //sizeof 是返回啥来着？加上0不？
    //这里有个坑！
    //sizeof 是返回“数据类型或变量在内存中实际占用的字节数（bytes）”！！
    //所以如果传 s[] ，能正常得到长度，因为实际占用的缘故，还会把最后的\0 加上
    //但是，如果声明是用指针*s，传s进去的时候，实际得到的是指针占用的内存数！跟数组实际大小没一点关系的！
    //比如 64 位系统上，返回 8
    
//    s = s+strlen(s)-1; //很经典的一个从最后开始取的方法。
    //哎，恶心。题目不让用string库。
    
    int len=0;
    while(*l != '\0'){
        len++;
        l++;
    }

    s = s+len; //因为strlen返回到结果会带上\0，这里len没有，所以不需要再-1.
    //这样的话我觉得用while好一点。
    while (p != s) {
        if(ch == *s){
            return s;
        }
        
        s--;
    }
    
    
    return NULL;
    
    /*end_edit*/
}
//爽！一遍过！✅
