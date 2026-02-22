//
//  Q2.c
//  LAB
//
//  Created by 邹嘉睿 on 2026.02.17.
//

#include <stdio.h>
#define SIZE 3

void swap2Rows(int ar[][SIZE], int r1, int r2);
void swap2Cols(int ar[][SIZE], int c1, int c2);
void display(int ar[][SIZE]);

int main(void){
    int array[SIZE][SIZE];
    int row1, row2, col1, col2;
    int i,j;
    int choice;
    
    printf("Select one of the following options: \n");
    printf("1: getInput()\n");
    printf("2: swap2Rows()\n");
    printf("3: swap2Cols()\n");
    printf("4: display()\n");
    printf("5: exit()\n");
    
    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the matrix (3x3): \n");
                for (i=0; i<SIZE; i++)
                    for (j=0; j<SIZE; j++)
                        scanf("%d", &array[i][j]);
                break;
                
            case 2:
                printf("Enter two rows for swapping: \n");
                scanf("%d %d", &row1, &row2);
                swap2Rows(array, row1, row2);
                printf("The new array is: \n");
                display(array);
                break;
                
            case 3:
                printf("Enter two columns for swapping: \n");
                scanf("%d %d", &col1, &col2);
                swap2Cols(array, col1, col2);
                printf("The new array is: \n");
                display(array);
                break;
                
            case 4:
                display(array);
                break;

            default:
                break;
        }
    } while (choice < 5);
    
    return 0;
}

void display(int ar[][SIZE]){
    int l,m;
    
    for (l = 0; l < SIZE; l++) {
        for (m = 0; m < SIZE; m++)
            printf("%d ", ar[l][m]);
        printf("\n");
    }
    //打印的函数，不用管。
}

void swap2Rows(int ar[][SIZE], int r1, int r2){
    /* edit */
    //那就是只需要交换两行就可以咯。
    //读取一行数据，然后存进一个小arry里面，再逐个替换?
    //好像很善良啊。
    //读取一行数据就是……固定的r1，那就相当于一层for就可以了。只需要一个index。
    //temp[index] = ar[r1][index], ar[r1][index] = ar[r2][index], ar[r2][index] = temp[index]

    
    int temp[SIZE];
    int index;
    
    for (index = 0; index<SIZE; index++) {
        temp[index] = ar[r1][index];
        ar[r1][index] = ar[r2][index];
        ar[r2][index] = temp[index];
    }
    
    /* end edit */
}

void swap2Cols(int ar[][SIZE], int c1, int c2){
    /* edit */
    //same，只是for的索引从外row变成了外col
    
    int temp[SIZE];
    int i;
    
    for (i=0; i<SIZE; i++) {
        temp[i] = ar[i][c1];
        ar[i][c1] = ar[i][c2];
        ar[i][c2] = temp[i];
    }
    
    /* end edit */
}

//爽！一遍过！
