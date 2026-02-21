//
//  ChineseHoroscope.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.01.31.
//

#include <stdio.h>

int main(void){
    /* start editing */
    //思路是先归并到1972～1983年吗？还是说直接 %12 看是哪个值？
    //直接 %12 吧，开销反而小很多
//    printf("pig ans = %d\n",1983%12); //3
    //那Monkey 就是 0
    //那 rooster 就是 1
    //Dog 2
    //Pig 3
    //Rat 4
    //Cow 5
    //Tiger 6
    //Rabbit 7
    //Dragon 8
    //Snake 9
    //Horse 10
    //Goat 11
    
    int yearOfBirth;
    int ret;
    
    while(1){
        //被自己输入的“meow” 爆破了，打印了600+行的Enter your birth year: chineseHoroscope: Rooster 才停下来。
        //发现了scanf的大坑，直接用的话虽然能读进yearOfBirth里，但是不能放错误输入。
        //更安全的写法是用返回值
        printf("Enter your birth year:\n");
        ret = scanf("%d",&yearOfBirth);
        if(ret != 1){
            break;
//            continue;
        }//robust!
        
        if(yearOfBirth == -1){
            break;
        }
        if(yearOfBirth % 12 == 0){
            printf("chineseHoroscope: Monkey\n");
        }else if (yearOfBirth % 12 == 1){
            printf("chineseHoroscope: Rooster\n");
        }else if (yearOfBirth % 12 == 2){
            printf("chineseHoroscope: Dog\n");
        }else if (yearOfBirth % 12 == 3){
            printf("chineseHoroscope: Pig\n");
        }else if (yearOfBirth % 12 == 4){
            printf("chineseHoroscope: Rat\n");
        }else if (yearOfBirth % 12 == 5){
            printf("chineseHoroscope: Cow\n");
        }else if (yearOfBirth % 12 == 6){
            printf("chineseHoroscope: Tiger\n");
        }else if (yearOfBirth % 12 == 7){
            printf("chineseHoroscope: Rabbit\n");
        }else if (yearOfBirth % 12 == 8){
            printf("chineseHoroscope: Dragon\n");
        }else if (yearOfBirth % 12 == 9){
            printf("chineseHoroscope: Snake\n");
        }else if (yearOfBirth % 12 == 10){
            printf("chineseHoroscope: Horse\n");
        }else if (yearOfBirth % 12 == 11){
            printf("chineseHoroscope: Goat\n");
        }else {
            printf("input error");
        }
        ret = 0;
        yearOfBirth = -1;
    }
    //mad又写死循环不加退出条件了，mac也卡了一瞬
    //记得每次更新啊！
    //或者其实把那两个移进While里就好了
    
    /* end */
    return 0;
}
//逻辑还是要再严谨一点，没读到成功的不能直接就写检查失败的，可能有中间情况。
//用 非 来想吧。
//只有在 scanf 失败时（ret != 1），才需要“清输入”
//ret == 0 和 ret != 1
//我超，问题其实挺大的，用 scanf 非常不优雅，推荐用fgets然后parse成数字。
//这里说的挺对，即使我在最后手动重置 yearOfBirth = -1，那相当于是读到这个变量
//而 scanf 的缓冲区里，依旧会存着那个error input（比如meow），依旧会让 ret = 0；
//比如我注释掉的代码，打开后输入meow，会直接卡死
//问题在输入的缓存区里，得while不断清缓存里的值直到读到换行 \n 结束，洗掉。

