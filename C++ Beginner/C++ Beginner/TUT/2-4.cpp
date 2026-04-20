//
//  2-4.cpp
//  C++ Beginner
//
//  Created by xxx on 2026.04.18.
//

#include <stdio.h>
//这链表题留到明天再写吧。写的我相思了。好困啊。
#include <iostream>
using namespace std;

struct Node {
    double value;
    Node* next;
};

void printList(Node* head) {
    Node* current = head;

    while (current) {
        cout << current->value << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

//可以拿来严肃复习下遍历打印、删表、尾插的写法。

void destroyList(Node*& head) {
    Node* nodePtr = head;
    Node* garbage = nullptr;

    while (nodePtr != nullptr) {
        // garbage keeps track of node to be deleted
        garbage = nodePtr;
        // Move on to the next node, if any
        nodePtr = nodePtr->next;
        // Delete the "garbage" node
        delete garbage;
        garbage = nullptr;
    }
    head = nullptr;
}

void insertNode2ListEnd(Node*& head, double newValue) {
    Node* newNode = new Node;
    newNode->value = newValue;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) { // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode; // Link last node to new node
}

// Function to concatenate two lists
void concateTwoLists(Node*& firstList, Node*& secondList) {
    // TO-DO: WRITE YOUR CODE HERE
    //
    //
    //
//    思路还是非常简单的，第一个list走到最后，next接第二个list，搞定。
    
    if(firstList == nullptr){return;}
    Node* curr = firstList;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = secondList;
    secondList = nullptr;
}

int main() {
    // Create first list: 1 -> 2 -> 3 -> NULL
    Node* firstList = nullptr;
    insertNode2ListEnd(firstList, 1);
    insertNode2ListEnd(firstList, 2);
    insertNode2ListEnd(firstList, 3);
    cout << "First List: ";
    printList(firstList);

    // Create second list: 4 -> 5 -> 6 -> NULL
    Node* secondList = nullptr;
    insertNode2ListEnd(secondList, 4);
    insertNode2ListEnd(secondList, 5);
    insertNode2ListEnd(secondList, 6);
    cout << "Second List: ";
    printList(secondList);

    // Create third list: 100 -> 200 -> 300 -> NULL
    Node* thirdList = nullptr;
    insertNode2ListEnd(thirdList, 100);
    insertNode2ListEnd(thirdList, 200);
    insertNode2ListEnd(thirdList, 300);
    cout << "Third List: ";
    printList(thirdList);

    // Create fourth list: 900 -> 800 -> NULL
    Node* fourthList = nullptr;
    insertNode2ListEnd(fourthList, 900);
    insertNode2ListEnd(fourthList, 800);
    cout << "Fourth List: ";
    printList(fourthList);


    // Concatenate secondList to firstList
    concateTwoLists(firstList, secondList);
    cout << "Concatenated First List: ";
    printList(firstList);

    // Concatenate thirdList to fourthList
    concateTwoLists(fourthList, thirdList);
    cout << "Concatenated Fourth List: ";
    printList(fourthList);


    // Destroy the concatenated list
    destroyList(firstList);
    destroyList(fourthList);

    return 0;
}
