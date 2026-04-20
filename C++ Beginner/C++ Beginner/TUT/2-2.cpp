//
//  2-2.cpp
//  C++ Beginner
//
//  Created by xxx on 2026.04.18.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

// Define the structure of a linked list node
struct StringNode {
    string name;
    StringNode* next;
};

// Function to print the linked list
void printList(StringNode* head) {
    StringNode* temp = head;
    cout << "Linked list: ";
    while (temp) {
        cout << temp->name << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to free allocated memory
void deleteList(StringNode*& head) {
    while (head) { // = while(head != nullptr){} 已严肃学习。
        StringNode* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

// Function to create a linked list from an array of strings
// 才发现是头插…… 这里写成尾插了。
void arrayToLinkedListEnd(const string* arr, int size, StringNode*& head) {
    // TO-DO: WRITE YOUR CODE HERE
    //
    //
    //
    //
    head = nullptr;
    if(arr==nullptr || size<=0){return;}
    
    StringNode* tail = nullptr;
    
    for (int i=0; i<size; i++) {
        StringNode* newNode = new StringNode; // new node every turn
        newNode->name = arr[i];
        newNode->next = nullptr;
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode; // 第二轮的时候，记住了第一轮的head位置，所以能更新！
            tail = newNode;
        }
    }
    
}
void arrayToLinkedList(const string* arr, int size, StringNode*& head) {
    // TO-DO: WRITE YOUR CODE HERE
    //
    //
    //
    //
    head = nullptr;
    if(arr == nullptr || size <=0 ){return;}
    
    for (int i=0; i<size; i++) {
        if(head == nullptr){
            StringNode* newNode = new StringNode;
            newNode->name = arr[i];
            newNode->next = nullptr;
            head = newNode;
        }else{
            StringNode* node = new StringNode;
            node->name = arr[i];
            node->next = head; // node->next 指向 原head 地址
            head = node; // 现在的 head 变量里，存的是 node 的地址。
            //因此头被更新为了 node 的地址，满足要求。
        }
    }
    
}

int main() {
    // Case 1
    string students[] = {"Alice", "Bob", "Charlie", "David"};
    int size = sizeof(students) / sizeof(students[0]);
    StringNode* head1 = nullptr;
    arrayToLinkedList(students, size, head1);
    printList(head1);

    // Case 2
    string companyNames[] = {"Microsoft", "Google", "Tecent", "Alibaba", "HP"};
    size = sizeof(companyNames) / sizeof(companyNames[0]);
    StringNode* head2 = nullptr;
    arrayToLinkedListEnd(companyNames, size, head2);
    printList(head2);
    
    // Case 3
    string companyNames2[] = {"Meowcrosoft", "Googol", "Tencent", "AbaAba", "HarryP~"};
    size = sizeof(companyNames2) / sizeof(companyNames2[0]);
    StringNode* head3 = nullptr;
    arrayToLinkedList(companyNames2, size, head3);
    printList(head3);

    deleteList(head1);
    deleteList(head2);
    deleteList(head3);
    return 0;
}
