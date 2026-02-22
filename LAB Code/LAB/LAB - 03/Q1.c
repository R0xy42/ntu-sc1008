//
//  Q1.c
//  LAB
//
//  Created by 邹嘉睿 on 2026.02.17.
//

#include <stdio.h>
void reverseAr1D(int ar[], int size);

int main(void){
    
    int ar[10];
    int size, i;
    
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    
    for (i=0; i <= size-1; i++)
        scanf("%d", &ar[i]);
    
    reverseAr1D(ar, size);
    
    printf("reverseAr1D(): ");
    
    if (size > 0) {
        for (i=0; i<size; i++)
            printf("%d ", ar[i]);
    }
    return 0;
}

void reverseAr1D(int ar[], int size){
    //也就是要反转array。
    //void无返回值，所以是直接对 ar 改。
    //好吧，那就设置一个 temp 然后每次都 temp = ar[size-1-i], ar[size-1-i] = ar[i] , ar[i] = temp?
    //到中间怎么处理呢？ 如果size是偶数，比如说 4，那么中间就是2和3， temp = ar[4-1-1] = ar[2], ar[2] = ar[1], ar[1] = ar[2],ok
    //如果size是奇数？比如5， 那么中间是3，实际index是2，01234，temp = ar[5-1-2] = ar[2], 相当于自己和自己交换，是OK的。
    
//    printf("enter\n");
    //OK说明是有进这个函数的，但是没有修改成功。代码逻辑出了点问题。
    
    int temp=0;
    int i;
    
    // 2 4 6
    
    for (i=0; i<size/2; i++) {
        temp = ar[size-1-i]; //temp = 6
        ar[size-1-i] = ar[i]; //ar[2] = ar[0], now ar[2] = 2
        ar[i] = temp; //ar[0] = 6
//        printf("ar[%d] now is:%d\n",i,ar[i]);
    }
}
//fail,没有reverse，原样打印了一遍。
//weird, ar[0] now is 3
//哦我知道了，因为下一次更新的时候也交换了。也就是说这个交换的操作后来又进行了一次，所以进行了偶数次交换后又回来了，如果要对半交换的话应该只进行一半。
//刚才如果不改 i<size 为 i<size/2，那么应该在偶数size的样例下成功。
//wochao?也失败了。会发生size次交换对吧？
//哦对的对的，就是会失败，因为size/2的前半段是反转过去了，但是size/2的后半段又全部反转回来了。所以如果走完size肯定是原样。
//我构思的时候就应该把 size/2 写清楚的。

//passed! 2.17 13:24
