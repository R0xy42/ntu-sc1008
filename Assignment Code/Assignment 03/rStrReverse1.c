//
//  rStrReverse1.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.03.14.
//
/*edit*/

/*custom header*/
//void reverseHelper(char *L, char *R);
/*end_edit*/
#include <stdio.h>
#include <string.h>
void rStrReverse1(char *s);
int main(void)
{
    char str[40], *p;

    printf("Enter a string: \n");
    fgets(str, 40, stdin);
    if (p=strchr(str,'\n'))
      *p = '\0';
    rStrReverse1(str);
    printf("rStrReverse1(): %s", str);
    return 0;
}
void rStrReverse1(char *s)
{
/*edit*/
/* Write your code here */
    
    //怎么处理呢
    //交换吗，然后到一半停下来？
//    printf("%c\n",s[3]); // ok, 是可以这样访问的。
    //双指针是比较好的思路，还是用双指针吧。写个helper函数。
    //否则只有左边界信息太难更新了。
/* ----------------------------------- */
    //这份代码是可用的，但是APAS不给用Helper函数，只得写在这一个函数里了。

//    if(s == NULL){
//        return;
//    }
//
//    size_t len = strlen(s);
//    if(len<=1){
//        return;
//    }//no need for reversal
//
//    reverseHelper(s, s+strlen(s)-1);
/* ----------------------------------- */
    
    
    //我超，还得是gpt啊，在一个函数里先正向挪过去到右边找到“base case“，然后再和左边的指针配合对换。
    //用一个函数模拟了双指针的效果。recursion退出的时候s天然充当右指针。
    //递归的“行进”和“回溯”阶段
    //这次的交换就发生在回溯阶段
    
    static char *left = NULL; //存左指针的地址。和s同步。
    static char *start = NULL;//存开始地址
    static int first = 1; //第一次flag
    
    
    if(s != NULL && first){
        left = s; // 记住左指针位置。
        start = s;
        first = 0;
    }
    
    if(s == NULL){
        //just in case s==NULL
        return;
    }
    
    //写退出条件
    if(*s == '\0'){
        return;
    }//bbzl, 第一次写的时候直接漏了 backslash.
    
    
    rStrReverse1(s+1);
    
    //现在才开始交换，value, not address!
    char temp;
    
    //s from right hand side
    //left from left
    //stop: left>=right
    if(!(left>=s)){
        temp = *left;
        *left = *s;
        *s = temp;
        
        left++;
    }
    
    //每一次用完static都归位！避免下一次污染：
    //什么时候归位：最外层递归结束！否则还没执行完归位就直接炸了。
    if(s == start){
        left = NULL;
        first = 1;
    }
    
    //f-word！ passed！✅ 终于。
//
/*end_edit*/
}

/* ----------------------------------- */

//void reverseHelper(char *leftPointer, char *rightPointer){
//    char temp;
//
//    if(leftPointer>rightPointer){
//        return;
//    }
//
//    temp = *leftPointer;
//    *leftPointer = *rightPointer;
//    *rightPointer = temp;
//
//    reverseHelper(leftPointer+1, rightPointer-1);
//
//}
/* ----------------------------------- */
