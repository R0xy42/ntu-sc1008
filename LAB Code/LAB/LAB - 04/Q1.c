//
//  Q1.c
//  LAB
//
//  Created by 邹嘉睿 on 2026.02.17.
//

#include <stdio.h>
#include <string.h>

char *sweepSpace(char *str);
int main(void)
{
   char str[80], *p;
 
   printf("Enter the string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n')) *p = '\0';
   printf("sweepSpace(): %s\n", sweepSpace(str));
   return 0;
}

char *sweepSpace(char *str)
{//跟pdf上的不太一样，用 index annotation的没了，只需要写 pointer 的就行了，省了点工作量。
    /*edit*/
   /* Write your code here */
    //如何理解这个 pointer 函数呢？
    
    //我们是直接对 str 操作，也就是最后的结果是在str里改的
    //拿到str，扫一遍，找到空格，替换成‘’
    //好像不行，不能直接换成空字符。
    //那先拆分？或者copy出来一份。
    
//    int begin_index=0; //用来获得第一个小字符串的起始位置
//    int end_index; // ending index;
    
    char* p = str;
    char* starting_p = NULL;
//    char* ending_p = NULL;
    
//    char temp[80];
    char str_cpy[80] = {0};
        
    while(*p != '\0'){
        while(*p == ' '){
            p++;
        } //eliminate starting ' ';
        //yeah, the basic thought is correct.
        
        if(*p == '\0') break; // all ' '
        
        starting_p = p;
        size_t len = 0; // we need to initialize len each cycle, since len is changing
        
        while(*p != ' ' && *p != '\0'){ //here, I missed the '\0' situaton
            p++; // update pos
            len++; // mark length
        }
        
//        ending_p = p; //no need, we only need starting point and length.
        
        size_t curlen = strlen(str_cpy);
//        printf("curlen is %zu\n",curlen);
        snprintf(str_cpy+curlen, sizeof((str_cpy)) - curlen, "%.*s", (int)len, starting_p);
        // starting from address of starting_p !!!
        // 把哪里开始的、长度多少的字符串，写进哪里开始的内存。
        
    }
    strcpy(str, str_cpy);
    
//    printf("str_cpy is: %s\n",str_cpy);
    //发现会每次循环都写strcpy，所以只剩最后一个写的了。问题出在 snprintf 那里
    
    return str; //问题出在这里，传了0回去，相当于NULL pointer
    /*end_edit*/
}

//之前看到各种垃圾字符都是因为没有对 temp 初始化，当然现在我们不用 temp了，改为直接用一个 str_cpy
//然后刚才str_cpy总是多一份 str 是因为在一开始我写了一个 strcpy函数 把str先复制过去了一份。删掉后就好了。
//此外，最大的坑点在于我没有引入curlen，所以每次都是从 str_cpy 的一开始来写入，这样就反复覆盖了。
//改成 str_cpy + len 就可以了。把“数组”当成一块内存中的指针指向之处，就很好理解那些个 *dst++ = *str++ 这种复制操作了
//但是为什么要curlen呢？
//明白了，写进哪是需要更新的，如果一直在 str_cpy 写，那就是反复覆盖了。


