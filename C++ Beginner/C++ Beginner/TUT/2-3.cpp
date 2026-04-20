//
//  2-3.cpp
//  C++ Beginner
//
//  Created by xxx on 2026.04.18.
//

#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;

// Node structure
struct Node {
    double value; // Can be any data type
    Node* next;
};


// Function to print the linked list
void printList(Node* head) {
    Node* current = head;// Start at the head of the list

    while (current) { // Equivalent to "current != nullptr"
        cout << current->value << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}


void destroyList(Node*& head)
{
    Node *nodePtr = head;  // Start at head of list
    Node *garbage = nullptr;

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


void insertNode2SortedList(Node*& head, double number)
{
    // TO-DO: WRITE YOUR CODE HERE
    //
    //
    //
    Node* prev = head;
    Node* curr = head;
    if(head == nullptr){
        Node* node = new Node;
        node->value = number;
        node->next = nullptr;
        head = node;
        return;
    }
    if(head->next == nullptr){
        Node* node = new Node;
        node->value = number;
        if(head->value > number){
            //to head;
            node->next = head;
            head = node;
        }else{
            head->next = node;
            node->next = nullptr;
        }
    }
    while(curr){
        // a < number < b
        //prev->value < number < curr->value;
        
        //头
        if(number < head->value){
            Node* nodeHead = new Node;
            nodeHead->value = number;
            nodeHead->next = head;
            head = nodeHead;
            return;
        }
        //等于的情况。
        if(fabs(prev->value-number) < 1e-7){
            //equal situation
            Node* newNode = new Node;
            newNode->value = number;
            newNode->next = curr;
            prev->next = newNode;
            return; //每次插入成功后都应立即 return
        }
        //找到，插入。
        if(prev->value < number && number < curr->value){
            //insert
            Node* newNode = new Node;
            newNode->value = number;
            newNode->next = curr;
            prev->next = newNode;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    
    //都没插入，说明比最后一个还大。
    //没这几行代码会插不进最大的。
    Node* newNode = new Node;
    newNode->value = number;
    newNode->next = nullptr;
    prev->next = newNode;
    
}



int main() {
    // Create the linked list
    Node* head = nullptr; // Start with an empty list

    // Insert values
    insertNode2ListEnd(head, 2.5);
    insertNode2ListEnd(head, 7.9);
    insertNode2ListEnd(head, 12.6);

    cout << "Original list: ";
    printList(head);

    insertNode2SortedList(head, 10.5);
    cout << "New list: ";
    printList(head);

    insertNode2SortedList(head, 1.5);
    insertNode2SortedList(head, 111.5);
    cout << "New list: ";
    printList(head);

    destroyList(head);
    return 0;
}

