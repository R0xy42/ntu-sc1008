//
//  StudentLinkedListManager.cpp
//  C++ Beginner
//
//  Created by Mars on 2026.04.19.
//

#include <stdio.h>
#include <iostream>
#include <limits>

using namespace std;

struct StudentNode{
    int id;
    string name;
    struct StudentNode* next;
};

int listLen(StudentNode* head);
void appendNode(StudentNode*& head, int id, const string& name);
void insertNodeAtPos(StudentNode*& head, int id, const string& name, int pos);
void deleteByName(StudentNode*& head, const string& targetName);
void reverseList(StudentNode*& head);
void printList(const StudentNode* head);
void freeList(StudentNode*& head);

int main(void){
    
    StudentNode* head = nullptr;
    bool flagToExit = false;
    
    int cmd;
    while(true){
        //print menu.
        cout << "Menu: \n";
        cout << "1) Append Node\n";
        cout << "2) Insert Node At Position\n";
        cout << "3) Delete All Nodes By Name\n";
        cout << "4) Reverse List\n";
        cout << "5) Print List\n";
        cout << "6) Exit\n";
        cout << "Enter command: ";
        
        //user input command.
        while(true){
            cin >> cmd;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Please enter a valid command!";
                continue;
            }
            break;
        }
        cin.ignore(1000,'\n'); // to capture the '\n' in input buffer zone.
        
        //menu, using switch case
        switch (cmd) {
            case 1:{
                cout << "Please enter student id(int): ";
                int id;
                cin >> id;
                while(cin.fail()){
                    cout << "Invalid id input! Please try again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cin >> id;
                }
                cin.ignore(1000,'\n'); // we need to clean up input buffer zone, especially for '\n', after cin, before getline. Since getline with cin will capture that '\n' and stop immediately.
                cout << "Please enter student name: ";
                string name;
                getline(cin,name);
                appendNode(head, id, name);
                break;
            } // !!! each case has its own scope! So without braces case 2 won't have 'name' variable initialized.
            case 2:{
                cout << "Please enter student id(int): ";
                int id;
                cin >> id;
                while(cin.fail()){
                    cout << "Invalid id input! Please try again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cin >> id;
                }
                cin.ignore(1000,'\n');
                cout << "Please enter student name: ";
                string name;
                getline(cin,name);
                cout << "Please enter pos: ";
                int pos;
                cin >> pos;
                while(cin.fail()){
                    cout << "Invalid id input! Please try again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cin >> pos;
                }
                cin.ignore(1000,'\n');
                insertNodeAtPos(head, id, name, pos);
                break;
            }
            case 3:{
                cout << "Please enter name you want to delete: ";
                string nameToDelete;
                getline(cin,nameToDelete);
                deleteByName(head, nameToDelete);
                break;
            }
            case 4:{
                cout << "Reverse List!" << endl;
                reverseList(head);
                break;
            }
            case 5:{
                cout << "Print list: ";
                printList(head);
                break;
            }
            case 6:{
                freeList(head);
                cout << "Exit Program!" << endl;
                flagToExit = true;
                break;
            }
            default:
                continue;
        }
        
        if(flagToExit){break;}
        cout << endl;
    }

    
    return 0;
}

int listLen(StudentNode* head){
    if(head == nullptr){
        return 0;
    }
    StudentNode* currPtr = head;
    int len=0;
    while(currPtr){
        currPtr = currPtr->next;
        len++;
    }
    return len;
}


void appendNode(StudentNode*& head, int id, const string& name){
    // create new node
    StudentNode* newNode = new StudentNode;
    newNode->name = name;
    newNode->id = id;
    newNode->next = nullptr;
    
    //check for empty list;
    if(head == nullptr){
        //insert at head;
        head = newNode;
        newNode->next = nullptr;
        cout << "Successfully append node (" << id << ", " << name << ") !\n";
        return; // Code should return after insert. on every brunch.
    }
    
    StudentNode* currPtr = head;
    while(currPtr->next){
        currPtr = currPtr->next;
    } // traverse to end;
    
    currPtr->next = newNode;
    
    cout << "Successfully append node (" << id << ", " << name << ") !\n";
}

void insertNodeAtPos(StudentNode*& head, int id, const string& name, int pos){
    // new Node
    StudentNode* newNode = new StudentNode;
    newNode->id = id;
    newNode->name = name;
    newNode->next = nullptr; //这里习惯不太好，应该每次new一个node的时候就把next初始化了。
    
    //check for empty list
    if(head == nullptr){
        head = newNode;
        cout << "Successfully inserted node (" << id << ", " << name << ") !\n";
        return;
    }
    
    if(pos<=1){
        //insert at head;
        StudentNode* tmp = head; //remember head;
        head = newNode;
        newNode->next = tmp;
        cout << "Successfully inserted node (" << id << ", " << name << ") !\n";
        return;
    }else if(pos>listLen(head)+1){
        //insert at end;
        StudentNode* currPtr = head;
        while (currPtr->next) {
            currPtr = currPtr->next;
        }
        currPtr = newNode;
        newNode->next = nullptr;
        cout << "Successfully inserted node (" << id << ", " << name << ") !\n";
        return;
    }else{
        //insert in between;
        //pos is 1-indexed, so use a count + walk to count
        StudentNode* currPtr = head;
        StudentNode* prevPtr = nullptr;
        for (int i=0; i<pos-1; i++) { //walk pos step;
            prevPtr = currPtr;
            currPtr = currPtr->next;
        }
        //1st time, prevPtr at 1, currPtr at 2;
        //pos-th time, prevPtr at pos, currPtr at pos+1;
        //to make the newNode becomes the pos-th node. upper limit should be pos-1
        //so walk (pos-1) times;
        //now prev at pos-1, as past, curr at pos, as future.
        prevPtr->next = newNode;
        newNode->next = currPtr;
    }
    
    cout << "Successfully inserted node (" << id << ", " << name << ") !\n";
}

void deleteByName(StudentNode*& head, const string& targetName){
    
//    //check for head;
//    if(head->name == targetName){
//        StudentNode* tmp = head; //remember now;
//        head = head->next; // go to next;
//        delete tmp; // delete now;
//        tmp = nullptr;
//        return;
//    }
    //woc! that's why it will only delete once
    
    bool hasDeleted = false;
    bool nodeExist = false;
    
    while (head != nullptr && head->name == targetName) {
        StudentNode* garbage = head;
        head = head->next;
        delete garbage;
        garbage = nullptr;
        hasDeleted = true;
    }
    
    if(head == nullptr){ // nothing to delete/everything has been deleted.
        if(hasDeleted){
            cout << "All nodes named " << targetName << " have been deleted!\n";
        }
        return;
    }
    
    StudentNode* currPtr = head;
    StudentNode* prevPtr = nullptr;
    
    //check for else
    while(currPtr){
        //if found, delete, if not ,go.
        if(currPtr->name == targetName){
            StudentNode* garbage = currPtr;
            currPtr = currPtr->next;
            prevPtr->next = currPtr;
            delete garbage;
            garbage = nullptr;
            nodeExist = true;
        }else{
            prevPtr = currPtr;
            currPtr = currPtr->next;
        }
    }
    
    if(nodeExist){
        cout << "All nodes named \"" << targetName << "\" have been deleted!\n";
        return;
    }
    
    cout << "Node with name \"" << targetName << "\" was not found!\n";
    
}

void reverseList(StudentNode*& head){
    // three pointers;
    // no need, 2 pointers + 1 temprary thing will work.
    StudentNode* prevPtr = nullptr;
    StudentNode* currPtr = head;
    
    //store future, curr points to prev,
    //handle single node and empty list separately;
    
    //no need to check for empty list here.
    
    while(currPtr){
        StudentNode* tmp = currPtr->next; // store the future.
        currPtr->next = prevPtr; // points to back
        prevPtr = currPtr; // update back
        currPtr = tmp; // update curr with future, keep things going.
    }
    
    head = prevPtr;
}


void printList(const StudentNode* head){
    //we cannot change *head, as it's a const StudentNode* type variable;
    //but we can change head, we can update its address within this func.
    
    if(head == nullptr){
        cout << "Empty\n";
        return;
    }
    while(head){
        cout << "(" << head->id << ", " << head->name << ")";
        cout << " -> ";
        //蚌埠住了，彻底蚌埠住了。
        //在这里竟然没有更新head。当时脑子抽了还是想下班吃饭了啊。
        head = head->next;
    }
    
    cout << "NULL\n";
}

void freeList(StudentNode*& head){
    if(head == nullptr){
        return;
    }
    StudentNode* garbage;
    
    while(head){
        garbage = head;
        head = head->next;
        delete garbage;
        garbage = nullptr;
    }
}
