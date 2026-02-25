//
//  platform1D.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.02.18.
//

#include <stdio.h>
#include <string.h>

int platform1D(int ar[], int size);
int main(void){
    
    
//    int length = 1000;
//    char* test[length];
//    test[1] = "12345";
//    test[100] = "123";
//    printf("length of test[1] is %lu\n",strlen(test[1]));
//    strcat(test[1], "2");
    //为啥炸了？又 BAD ACCESS了，但是我这里也没非法访问……？有吗？
    //懂了，又忘记了，这些是字符串字面量！是不能修改的！
    
//    有思路了，直接开个大的二维数组，然后往里拼接字符串，下标就是我们的读到的数字。个数用长度表示，
    //读到就再后面补东西。
    //然后直接扫过去。（好像很不优雅……）
    
    //cnt?
    //唉有 key-value pair 就好使很多
    //用上新学的struct！ //额，不能改header好像。
    
    
    int i,b[50],size;
    
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    
    for (i=0; i<size; i++){
        scanf("%d",&b[i]);
    }
    printf("platform1D(): %d\n", platform1D(b,size));
    
    
    
    return 0;
}

int platform1D(int ar[], int size){
    /* Write your code here */
    int i;
    int cnt=0,max=0;
    if (size <= 0) return 0;  // 虽然题目测试里 size>=1，但我们写得健壮一点没坏处

    
//    int cnt[1000]={0};
    
    //双指针的思路，一个扫总长度(i)，一个从 0 开始扫。(num), 一个计数(cnt). if greater than cnt, update
    //草，我想复杂了。不会出现那种情况。 platform之所以起名为platform是有原因的。
    //只需要上下两个比较就可以了。一致就++；然后写cnt，大了就覆盖。
    
//    for (i=0; i<size; i++) {
//        num = ar[i];
//        for (j=0; j<size; j++) {
//            if(num == ar[j]){
//                //第一次，0
//                //那后面的怎么办？如果 0 1 0呢？这样没有记忆啊。
//                //改用cnt数组
//                //两个没有记忆性带来阻碍： 1、哪个数最多。2、最多是几次。
//                cnt[num]++; //写入cnt[0];
//            }
//        }
//        
//        i++;
//    }
    
    for (i=0; i<size-1; i++) { //确实，gpt说的对，我又忘记这里的越界访问了。似乎是当时 java 犯过的错误。
        //到 i+1 会==size， 然后ar[size] 就超容了。
        //改成 -1 就好了，反正到size-2也会比较size-2和size-1；
        if(ar[i] == ar[i+1]){
            cnt++;
        }else {cnt=0;}
        
        if(cnt>max){
            max = cnt;
        }
        
//        if(ar[i] != ar[i+1]){
//            cnt=0;
//        }//这里其实也可以合并到上面去，“如果下一次不等就中断连胜”这样。
    }
    
    
    return max+1; //因为两个相等只算了一次，相当于插空，空位数比柱子数少1
}

