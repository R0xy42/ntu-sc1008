//
//  computeExp.c
//  LAB
//
//  Created by 邹嘉睿 on 2026.03.14.
//

/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
typedef struct {
    float operand1, operand2;
    char op;
} bexpression;
float compute1(bexpression expr);
float compute2(bexpression *expr);
int main(void)
{
    bexpression e;
    int choice;

    printf("Select one of the following options: \n");
    printf("1: compute1()\n");
    printf("2: compute2()\n");
    printf("3: exit()\n");
    do {
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            printf("Enter expression (op1 op2 op): \n");
            scanf("%f %f %c", &e.operand1, &e.operand2, &e.op);
            printf("compute1(): %.2f\n", compute1(e));
            break;
         case 2:
            printf("Enter expression (op1 op2 op): \n");
            scanf("%f %f %c", &e.operand1, &e.operand2, &e.op);
            printf("compute2(): %.2f\n", compute2(&e));
            break;
      }
    } while (choice < 3);
    return 0;
}
float compute1(bexpression expr)
{
/*edit*/
/* Write your code here */
    //oh, 算加减乘除的，我当时学了switchcase 和 struct都想搞这个。
    float ans;
    switch (expr.op) {
        case '+':
            ans = expr.operand1 + expr.operand2;
            break;
            
        case '-':
            ans = expr.operand1 - expr.operand2;
            break;
            
        case '*':
            ans  = expr.operand1 * expr.operand2;
            break;
            
        case '/':
            if (expr.operand2 == 0) {
                ans = 0;
                break;
            }
            ans = expr.operand1 / expr.operand2;
            break;
            
        default:
            ans = 0;
            break;
    }
    
    return ans;

/*end_edit*/
}
float compute2(bexpression *expr)
{
/*edit*/
/* Write your code here */
    float ans;
    switch (expr->op) {
        case '+':
            ans = expr->operand1 + expr->operand2;
            break;
            
        case '-':
            ans = expr->operand1 - expr->operand2;
            break;
            
        case '*':
            ans  = expr->operand1 * expr->operand2;
            break;
            
        case '/':
            if (expr->operand2 == 0) {
                ans = 0;
                break;
            }
            ans = expr->operand1 / expr->operand2;
            break;
            
        default:
            ans = 0;
            break;
    }
    
    return ans;


/*end_edit*/
}
