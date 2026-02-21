//
//  binaryToDec.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.01.29.
//

/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#include <math.h>
int main(void)
{
    /*edit*/
    /* Write your code here */
    
    //思路是读取各个位，判断是0还是1，然后乘以 2 的power次方，累加。
    
    int binary,decimal=0,x;
    int digit=1;//2的digit-1次方。似乎这个要单独算。
    
    printf("Enter a binary number:\n");
    scanf("%d",&binary);
    
    x = binary;
    //不知道进多少个数字，所以while
    //当数字检测到为1时，把当前的2的digit-1次方加到结果（decimal）上。
    //当前2的digit次方等于多少呢？ 比如2*2*2*2*2连乘，这是5个2连乘，也就是digit = 6, (digit-1).注意digit是实际输入的位数，从1开始计。
        //那最好把2的0次方单独拿出来判断。此时digit = 1，如果是1就直接+1. 0 就不动。
        //而要乘以的2的幂是 总共（digit-1），用for的话……
    //5个2连乘的话，应该用for i=0<digit-1，i++；
    int i,add=1;
    while(x>0){
        if(binary % 2 == 1){//1
            for(i=0;i<digit-1;i++){
                add *= 2;
            }
            decimal += add;
            //记得重置add啊！
            add = 1;
        }
        binary /= 10; //记得更新binary啊！
        x /= 10;
        digit++;
    }
    
    
    printf("The equivalent decimal number: %d\n",decimal);

    /*end_edit*/
    return 0;
}

//爽啊！😊 修了binary的更新和add的重置后APAS提交一遍过！所有sample tests 全pass！我还上网找了个2进制转10进制的工具验证了下。太爽了！

