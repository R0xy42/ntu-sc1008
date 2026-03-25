//
//  ASairlines.c
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.03.14.
//

#include <stdio.h>
#include <string.h>
#define EMPTY 0
#define TAKEN 1

/* structure */
typedef struct {
    char name[20];
    int ID;
    int status;
}Seat;


/* functions */
//please, do remember to write it behind #include and struct defintion!!!!!
void listInitializer(Seat *seat, int seatLen);
void listTakenSeat(Seat *seat, int seatLen);
void assignSeat(Seat *seat, int seatLen);
void removeSeat(Seat *seat, int seatLen);



int main(void){
    
    int seatLen = 5;
    Seat seat[seatLen];
    
    /* initialization */
    listInitializer(seat,seatLen);
    
    /* menu */
    printf("NTU AIRLINES SEATING RESERVATION PROGRAM:\n");
    printf("1: listTakenSeat()\n");
    printf("2: assignSeat()\n");
    printf("3: removeSeat()\n");
    printf("4: quit\n");
    
    int option;
    //while + switch case will do
    do {
        printf("Enter your choice:\n");
        
        if(scanf("%d",&option) != 1){
            int charInt;
            while((charInt = getchar()) != '\n' && charInt != EOF); //吃字
            continue;
        }
        
        switch (option) {
            case 1:
                printf("listTakenSeat():\n"); //when executed, print.
                listTakenSeat(seat,seatLen);
                break;
            case 2:
                printf("assignSeat():\n");
                assignSeat(seat,seatLen);
                break;
            case 3:
                printf("removeSeat():\n");
                removeSeat(seat,seatLen);
                break;
            case 4:
                break;
            default:
                continue;
        }
    } while (option!=4);
    
}

//unbengable
//我完全忘记了题目给了个status字段来表示是否occupied
//反而自己写了个“EMPTY”然后用愚蠢的strcmp。
//我服了

void listInitializer(Seat *seat, int n){
    for (int i=0; i<n; i++) {
        seat[i].ID = i+1;
        strcpy(seat[i].name[0], '\0');
        seat[i].status = EMPTY;
    }
}

void listTakenSeat(Seat *seat, int seatLen){
    int remain=seatLen;
    for (int i=0; i<seatLen; i++) {
        if (seat[i].status == TAKEN) { //not 0, means they're not the same - occupied!
            printf("Customer name: %s\n",seat[i].name);
            printf("Seat number (ID): %d\n",seat[i].ID);
            remain--;
        }
    }
    if (remain == seatLen) {
        //no deduction, empty plane
        printf("The seat assignment list is empty\n");
    }
    
}

void assignSeat(Seat *seat, int seatLen){
    int seatNum=0;
    char seatName[20];
    
    /* plane vancacy check */
    int remain=0;
    //一开始就先检查plane满没满。
    for (int i=0; i<seatLen; i++) {
        if(seat[i].status == EMPTY){
            //==0: same string, empty
            // !=0: different string. occupied
            remain++;
        }
    }
    if(remain == 0){
        //no vacancy
        printf("The plane is full\n");
        
        //end of func:
        return;
    }
    
    
    printf("Enter the seat number:\n");
    while(1){
//        scanf("%d",&seatNum);
        
        //valid input check
        if(scanf("%d",&seatNum) != 1){
            //means that input is invalid.
            //吃字循环，直到读到'\0' OR EOF 为止。
            int ch;
            while((ch = getchar()) != '\n' && ch != EOF );
            continue;
            //第……0次检查。非法输入（非数字）
        }
        
        if(!(seatNum>=1 && seatNum <= seatLen)){
            printf("Please enter a seat number between 1 and 5\n");
//            getchar(); // mad,如果这里seat number输入非数字的字符，程序会死循环然后炸掉。还没想好怎么解决。
            //不够robust
            continue;
        }//第一次检查，无效数字就重来。
        
        
        //这里只检查用户选中的那个座位
        if (seat[seatNum - 1].status == TAKEN) {
            printf("Occupied! Please choose another seat\n");
            continue; //第二次检查，有人坐了就重来
        } else {
            printf("Enter customer name:\n");
//            for (int i=0; i<seatLen; i++) {
//                if(seat[i].ID == seatNum){
//                    getchar();
//                    fgets(seatName, 20, stdin); //read in names
//                }
//                char *p;
//                if(p = strchr(seatName, '\n')){
//                    *p = '\0';
//                }//\n. replaced with '\0'
//                //fgets includes 0, it reads most (size-1) characters.
//            }
            getchar();
            fgets(seatName, 20, stdin);
            
            char *p;
            if(p = strchr(seatName, '\n')){
                *p = '\0';
            }//\n. replaced with '\0'
            
            strcpy(seat[seatNum - 1].name, seatName);
            printf("The seat has been assigned successfully\n");
            seat[seatNum-1].status = TAKEN;
            break;//如果成功分配，就直接退出循环了。把代码挪进来的时候漏了这个
            
        }
    }
    
}


void removeSeat(Seat *seat, int seatLen){
    int seatNumRemoval=0;
    
    /* plane vancacy check */
    int remain=0;
    //一开始就先检查plane满没满。
    for (int i=0; i<seatLen; i++) {
        if(seat[i].status == EMPTY){
            //==0: same string, empty
            // !=0: different string. occupied
            remain++;
        }
    }
    if(remain == seatLen){
        printf("All the seats are vacant\n");
        
        //end of func:
        return;
    }
    
    printf("Enter the seat number:\n");
    while(1){
//        scanf("%d",&seatNumRemoval);
        //same old question. check input validity
        
        if(scanf("%d",&seatNumRemoval) != 1){
            int ch;
            while((ch = getchar()) != '\n' && ch !=EOF);
            continue;
        }
        
        if(!(seatNumRemoval>=1 && seatNumRemoval <= seatLen)){
            printf("Please enter a seat number between 1 and 5\n");
            continue;
        }//第一层检查，输入的ID是否合法
        if(seat[seatNumRemoval-1].status == EMPTY){
            printf("Empty! Enter another seat number for removal\n");
            continue;
            //第二次检查，座位是否空。
        }else{
//            strcpy(seat[seatNumRemoval - 1].name, "EMPTY");
            seat[seatNumRemoval-1].status = EMPTY;
            seat[seatNumRemoval-1].name[0] = '\0';
            printf("Removal is successful\n");
            break;//移除成功，退出while
        }
    }//这种读取输入应该写在循环里，如果输入错误了回到原点重来。
    
}
