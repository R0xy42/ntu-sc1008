//
//  Q2.c
//  LAB
//
//  Created by 邹嘉睿 on 2026.02.18.
//


/*custom header*/


#include <stdio.h>
#include <string.h>
#define SIZE 10
#define INIT_VALUE 999
void printNames(char nameptr[][80], int size);
void readNames(char nameptr[][80], int *size);
int findTarget(char *target, char nameptr[][80], int size);
int main(void)
{
   char nameptr[SIZE][80], t[40], *p;
   int size, result = INIT_VALUE;
   int choice;
   
   printf("Select one of the following options: \n");
   printf("1: readNames()\n");
   printf("2: findTarget()\n");
   printf("3: printNames()\n");
   printf("4: exit()\n");
   do {
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            readNames(nameptr, &size);
            break;
         case 2:
            printf("Enter target name: \n");
            scanf("\n");
            fgets(t, 80, stdin);
            if (p=strchr(t,'\n')) *p = '\0';
            result = findTarget(t, nameptr, size);
            printf("findTarget(): %d\n",  result);
            break;
         case 3:
            printNames(nameptr, size);
            break;
      }
   } while (choice < 4);
   return 0;
}

//ok啊，就是输入（读取）名字、打印出来、和一个搜索的功能。

void printNames(char nameptr[][80], int size)
{
    /*edit*/
   /* Write your program code here */
    int i;
    for (i=0; i<size; i++) {
        printf("%s ",nameptr[i]); //第 i 个元素。每个元素是一个字符串
    }
    
    printf("\n");
    /*end_edit*/
}
void readNames(char nameptr[][80], int *size)
{
    /*edit*/
   /* Write your program code here */
    int i=0;
    char *p;
    printf("Enter size:\n");
    scanf("%d",size); //size这里会有一个 \n 没读到，留在缓存区里，要 getchar 拿掉
    getchar();
    printf("Enter %d names:\n",*size);
    while(i<*size){
//        getchar();
        //print size 调试一下吧。
//        printf("size and i is: %d and %d\n",*size,i);
        //?我超？为什么直接就size and i is: 6 and 0，毫无依据地跟了第二行：size and i is: 6 and 1。
        //我知道了，又是残留了换行符的原因。得 getchar 一个。
//        fgets(nameptr[i], 80, stdin); //我们是要读取字符串然后存入nameptr的每一个元素中对吧？
        //为什么不生效呢？ 感觉对二维的写入还是很生疏啊。不知道每个量的格式是什么，函数返回的是什么，写进去的是什么。格式对不对得上。
        //原来如此！是 nameptr+i 在先，先按base地址索引，然后移动i，再dereference拿到实际元素的值，*(nameptr+i)
        //while *nameptr + i is wrong!
        //或者直接 nameptr[i] 也可以。
        
        //吗的，是 fgets 的问题，我忘记了，这函数是按读到'\0' or '\n' 结束的！
        //直接用 scanf 就可以了……
        scanf("%79s",nameptr[i]);
        
        // 去掉行末的 '\n'，方便后面比较 / 打印
        if ((p = strchr(nameptr[i], '\n')) != NULL) {
            *p = '\0';
        }
        
        i++;
    }
    //不知道为啥死循环了，卡在 Enter your choice：1 里出不来。
    //好好好，没写enter size让我们自己写呢。
    //输入size后怎么还是死循环了？fgets没生效?
    //神秘！死循环，然后 i = 5 之后直接重置回 0 了。
    /*end_edit*/
}
int findTarget(char *target, char nameptr[][80], int size)
{
    /*edit*/
   /* Write your program code here */
    int i;
    for (i=0; i<size; i++) {
        if(strcmp(nameptr[i], target) == 0){
            return i;
        }
    }

    return -1;
    /*end_edit*/
}
