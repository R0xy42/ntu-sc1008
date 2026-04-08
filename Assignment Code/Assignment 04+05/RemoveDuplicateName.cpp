//
//  RemoveDuplicateName.cpp
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.04.04.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
 
struct StringNode {
    string name;
    StringNode* next;
};
 
void printList(const StringNode* head) {
    const StringNode* temp = head;
    while (temp) {
        cout << temp->name << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
 
void append(StringNode*& head, const string& name) {
    StringNode* newNode = new StringNode;
    newNode->name = name;
    newNode->next = nullptr;
    if (!head) {
        head = newNode;
        return;
    }
    StringNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}
 
void freeList(StringNode*& head) {
    while (head) {
        StringNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Remove duplicate names from the linked list
void removeDuplicatedNames(StringNode*& head) {
    // TO-DO: Write Your Code Here
    //
    //
    //唔…… 比较直观的想法就是先存 head 的名字，然后指针扫过去(for)，然后当找到匹配的名字的时候，用 tmp 指针记住这个位置，flag置为1，然后指针继续走，当找到相同名字且flag时，删除当前node。
    //然后外层循环是更新不同的名字。直到确保所有名字都被遍历。 用慢指针实现。
    //emm，还可以优化下，直接从上次扫过的地方开始扫，不用重复扫描。就让curr每次外圈循环为slow就行

    //check for head null:
    if(head == nullptr || head->next == nullptr) return;
    
    StringNode* currPtr = head;
    StringNode* prevPtr = nullptr;
    StringNode* slowPtr = head;
    
    while(slowPtr != nullptr){
        currPtr = slowPtr->next;
        prevPtr = slowPtr;
        
        while(currPtr != nullptr){
            if(slowPtr->name == currPtr->name){
                //same name, delete
                StringNode* rubbishPtr = currPtr; // 存放垃圾
                currPtr = currPtr->next; // 记住未来
                prevPtr->next = currPtr; // 断开过去
                
                delete rubbishPtr; // 丢掉垃圾
                rubbishPtr = nullptr; // 防止未来有人捡起垃圾。
            }else{
                //not found in this node, update ptrs;
                prevPtr = currPtr;
                currPtr = currPtr->next;
            }
        }
        
        slowPtr = slowPtr->next;
    }
    
}

int main() {
    StringNode* head = nullptr;
 
    cout << "1) Append Node" << endl;
    cout << "2) Print List" << endl;
    cout << "3) Remove Duplicates" << endl;
    cout << "4) Exit" << endl;
 
    int cmd;
    do {
        cout << "Enter command: " << endl;
        cin >> cmd;
 
        switch (cmd) {
        case 1: {
            string name;
            cin >> name;
            append(head, name);
            break;
        }
        case 2:
            printList(head);
            break;
        case 3:
            cout << "Removing Duplicates" << endl;
            removeDuplicatedNames(head);
            break;
        case 4:
            break;
        default:
            cout << "Unknown cmd: " << cmd << endl;
        }
    } while (cmd != 4);
 
    freeList(head);
    return 0;
}
