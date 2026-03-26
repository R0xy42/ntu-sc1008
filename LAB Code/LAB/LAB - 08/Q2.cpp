//
//  Q2.cpp
//  LAB
//
//  Created by 邹嘉睿 on 2026.03.26.
//

#include <stdio.h>
#include <iostream>
using namespace std;
struct MarkNode {
  int mark; // Changed to int
  MarkNode* next;
};
// Function to insert a node at the end of the linked list
void insertNode2ListEnd(MarkNode*& head, int newValue) {
  MarkNode* newNode = new MarkNode;
  newNode->mark = newValue;
  newNode->next = nullptr;
  if (head == nullptr) {
    head = newNode;
    return;
  }
  MarkNode* temp = head;
  while (temp->next != nullptr) { // Traverse to the last node
    temp = temp->next;
  }
  temp->next = newNode; // Link last node to new node
}
void destroyList(MarkNode*& head)
{
  MarkNode *nodePtr = head; // Start at head of list
  MarkNode *garbage = nullptr;
  while (nodePtr != nullptr)
  {
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
// Function to get the value of the n-th node
int getNthNodeValue(const MarkNode* head, int n) {
// TO-DO: WRITE Your code here
//
//
int count = 0;
    if(head == nullptr){return -1;}
    while(head != nullptr){
        count++;
        if(n == count){
            return head->mark;
        }
        head = head->next;
    }

//    if(n>count){
//        return -1;
//    }
    //出while = 没找到
    return -1;

}
int main() {
    MarkNode* head = nullptr; // Initialize an empty linked list

    int size;
    cout << "Enter size of list:" << endl;
    cin >> size;
    cout << "Enter elements:" << endl;
    for(int i = 0; i < size; i++) {
        int value;
        cin >> value;
        insertNode2ListEnd(head, value);
    }

    while(true) {
        cout << "Enter n: " << endl;
        int n;
        cin >> n;
        if (n == -1) break;
        cout << getNthNodeValue(head, n) << endl;
    }

    // Clean up memory
    destroyList(head);
    return 0;
}


