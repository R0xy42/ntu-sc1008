//
//  findLongShortStr.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.02.20.
//

#include <stdio.h>
#include <string.h>
#define N 20
void findLongShortStr(char str[N][81], char *longStr, char *shortStr, int size);
int main(void)
{
   char str[N][81],longStr[81],shortStr[81],*p;
   int i,size;
   char dummy;
   
   printf("Enter number (size) of strings: \n");
   scanf("%d", &size);
   scanf("%c",&dummy);
   for (i=0; i<size; i++){
      printf("Enter string %d: \n", i+1);
      fgets(str[i],81,stdin);
      if ( p=strchr(str[i],'\n') ) *p = '\0';
   }
   findLongShortStr(str, longStr, shortStr, size);
   printf("longest string: %s %lu\n",longStr,strlen(longStr));
   printf("shortest string: %s %lu\n",shortStr,strlen(shortStr));
   return 0;
}

void findLongShortStr(char str[N][81], char *longStr, char *shortStr, int size)
{
    /*edit*/
   /* Write your code here */
    
    //比较straightforward. 感觉用 sizeof(str[i]）就可以了
    //max 和 min，哪个大更新哪个为max，小更新为min。
    
    size_t max,min,len;
    max=0;
    min=80;
    int i;
    for (i=0; i<size; i++) {
        len = strlen(str[i]); //优化，每次循环算一次len就可以了，没必要算两次。
        if(len>max){
            
            max = len;
//            longStr = str[i];
            strcpy(longStr, str[i]);
        }
        
        if(len<min){
            min = len;
//            shortStr = str[i]; 这两个写的有问题。因为只是局部的指针。并没有绑定。
            strcpy(shortStr, str[i]);
            //为什么用strcpy拷贝就可以呢？
        }
    }
    //meow 12345
//    printf("max is: %lu\n",max); //5
//    printf("min is: %lu\n",min); //4
//    printf("long: %s\n",longStr); //12345
    //说明是读到了的
    //那问题出在返回？
    //对的，不知道怎么把二维数组的一个元素作为字符串整体返回。
    //现在的写法肯定有问题。赋值返回哪一块。
    
    

    
    /*end_edit*/
}
