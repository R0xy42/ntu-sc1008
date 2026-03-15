//
//  mayTakeLeave.c
//  LAB
//
//  Created by 邹嘉睿 on 2026.03.14.
//

/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#define INIT_VALUE 1000
typedef struct {
    int id;                   /* staff identifier */
    int totalLeave;    /* the total number of days of leave allowed */
    int leaveTaken;   /* the number of days of leave taken so far */
    //ok, 大概是检查员工还剩几天假期。看id然后看总共能修几天，已经修了几天来决定剩下还有几天。
} leaveRecord;
int mayTakeLeave(leaveRecord list[], int id, int leave, int n);
void getInput(leaveRecord list[], int *n);
void printList(leaveRecord list[], int n);
int main(void)
{
    leaveRecord listRec[10];
    int len;
    int id, leave, canTake=INIT_VALUE;
    int choice;

    printf("Select one of the following options: \n");
    printf("1: getInput()\n");
    printf("2: printList()\n");
    printf("3: mayTakeLeave()\n");
    printf("4: exit()\n");
    do {
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            getInput(listRec, &len);
            printList(listRec, len);
            break;
         case 2:
            printList(listRec, len);
            break;
         case 3:
            printf("Please input id, leave to be taken: \n");
            scanf("%d %d", &id, &leave);
            canTake = mayTakeLeave(listRec, id, leave, len);
            if (canTake == 1)
               printf("The staff %d can take leave\n", id);
            else if (canTake == 0)
               printf("The staff %d cannot take leave\n", id);
            else if (canTake == -1)
               printf("The staff %d is not in the list\n", id);
            else
               printf("Error!");
            break;
      }
    } while (choice < 4);
    return 0;
}
void printList(leaveRecord list[], int n)
{
    int p;

    printf("The staff list:\n");
    for (p = 0; p < n; p++)
      printf ("id = %d, totalleave = %d, leave taken = %d\n",
         list[p].id, list[p].totalLeave, list[p].leaveTaken);
}
void getInput(leaveRecord list[], int *n)
{
/*edit*/
/* Write your program code here */
    int number;
    printf("Enter the number of staff records:\n");
    scanf("%d",&number);
    *n = number;
    int i=0;
    while (i<number) {
        printf("Enter id, totalleave, leavetaken:\n");
        scanf("%d %d %d",&list[i].id,&list[i].totalLeave,&list[i].leaveTaken);
        i++;
    }
    
/*end_edit*/
}
int mayTakeLeave(leaveRecord list[], int id, int leave, int n)
{
/*edit*/
/* Write your program code here */
    //1 approved
    //0 not approved
    //-1 no such guy in list
    //先遍历，找到id。然后if判断 taken + applyForLeave <= total
    //没找到：最后默认return -1；
    for (int i=0; i<n; i++) {
        if(id == list[i].id){
            if(list[i].leaveTaken + leave <= list[i].totalLeave){
                return 1;
            }else return 0;
        }
    }
    return -1;
/*end_edit*/
}
