//
//  2-1.cpp
//  C++ Beginner
//
//  Created by xxx on 2026.04.18.
//

#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
};

// TO-DO: You need to implement this function
int getListLen(const ListNode* head) { //correct, no need to modify head, so * not *&
    // TO-DO: WRITE YOUR CODE HERE
    //
    //
    //
    int listLen=0;
    while(head != nullptr){
        head = head->next;
        listLen++;
    }
    return listLen;
}

int main() {
    //我勒个 hardcoding 啊。
    //第一眼看：nextnextnextnext……？
    //第二眼看：……补兑
    //第三眼看：！？强强？！
    
    // Creating a simple linked list: 10 -> 20 -> 30 -> 40
    ListNode* head = new ListNode;
    head->value = 10;
    head->next = nullptr;
    cout << "Length of the linked list: " << getListLen(head) << endl;

    head->next = new ListNode;
    head->next->value = 20;
    head->next->next=nullptr;
    cout << "Length of the linked list: " << getListLen(head) << endl;

    head->next->next=new ListNode;
    head->next->next->value = 30;
    head->next->next->next = nullptr;
    cout << "Length of the linked list: " << getListLen(head) << endl;

    head->next->next->next=new ListNode;
    head->next->next->next->value = 40;
    head->next->next->next->next = nullptr;
    cout << "Length of the linked list: " << getListLen(head) << endl;

    // Free allocated memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;

    return 0;
}
