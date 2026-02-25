//
//  minChrToEnd minChrToEnd minChrToEnd.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.02.18.
//

/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#include <string.h>
void minCharToEnd(char *str);
int main(void)
{
    char str[80];

    printf("Enter a string: \n");
    scanf("%s",str);
    minCharToEnd(str);
    printf("minCharToEnd(): %s",str);
    return 0;
}

void minCharToEnd(char *str)
{
    /*edit*/
    /* Write your code here */
    //一、找。二、换到队尾
    //好找，直接ascii比大小，一遍for扫过去，然后一个变量记住最小的值，如果有更小出现，更新
    //找完之后怎么换到队尾呢？
    //snprintf？，先记住那个最小字符，然后把前后两段字符串拼接起来。再add这个字符。
    
//    需要用指针指向那个最小的原始位置，然后计算出到队尾的距离
//    先设置一个最大的，如果小就换
    
    char *ptrmMinC = str; //used to find micChar
    char minC = 122; //get the min char
    char *ptrStored = NULL;
    unsigned long lLen = 0;
    unsigned long rLen = 0;
    
    while (*ptrmMinC != '\0') {
        if(*ptrmMinC < minC){
            minC = *ptrmMinC;
            lLen = ptrmMinC - str;
//            printf("lLen is: %lu\n",lLen);
            rLen = strlen(str) - lLen - 1;
//            printf("rLen is: %lu\n",rLen); // 4 —— 总长度是6（加0），a的右边确实是4。
            //也就是写4位。
            
            ptrStored = ptrmMinC + 1; //ptrStored指向最小的字符。
            //懂了，问题出在这里，应该写 +1 的，因为最小字符自己不写。
            //correct!
            //这个调试的过程真是宝贵的经验啊。仿佛回到了23年还没用上先进的人工智能，gpt-3都是人工智障的那个
            //自己熬夜debug的年代。
            //感觉……非常复古。哈哈哈哈。
       
            //有点问题，如果在最后一位（cba）会挂掉。哪里没算清楚。
            //啊？我在本地跑是cba啊。没问题啊。为什么APAS上只剩a了？？？？？？
        }
        ptrmMinC++;
    }
    //如果左边没有，怎么办。比如第一个字符就是最小。此时 lLen 应该为 0
    
    char tmp[80];
    
    snprintf(tmp, sizeof(tmp), "%.*s%.*s%c",(int)lLen,str,(int)rLen,ptrStored,minC);
    
    strcpy(str, tmp);
    //第一次写这么长的snprintf，还挺有成就感（）。这个函数的语法应该算彻底记住了。
    //额看来还是不精。snprintf不要边写边读！这是第一个坑。要写入缓存区里。然后最后 strcpy 到原字符串里。
    //第二个坑是上道题才写过 sizeof 和 strlen 的区别，这又忘了（）。sizeof是变量的实际占用的内存空间的大小
    //如果传进来的是一个指针，那就只有 8Bytes。（64位系统）
//    一旦“传参”出去，数组就退化成指针：
    
    
    
    /*end_edit*/
    //passed✅
}
