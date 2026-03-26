//
//  lec-2-linkedList.cpp
//  C++ Beginner
//
//  Created by 邹嘉睿 on 2026.03.18.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "NodeHelper.hpp"
//#define EXIT_SUCCESS 0 // same as in MacOS 26 manuals
//#define EXIT_FAILURE 1
using namespace std;

int main(void){
    
    Node* head = nullptr;
    printList(head); //Empty List!
    
    /* add node */
    insertNodeAtEnd(head, 1, "Hellow!");
    insertNodeAtEnd(head, 2, "C++ yeah!");
    insertNodeAtEnd(head, 42, "Welcome to Earth Online!");
    
    /* traverse */
    printList(head);
    printId(head); //1 -> 2 -> 42 -> NULL
    
    /* delete node */
    cout << "-- Execute node deletion -- " << endl;
    deleteNode(head, 2);
    printList(head);
    
    /* delete list*/
    deleteList(head);
    printList(head); //Empty List!
    
    delete head;
    
    printList(head);//Empty List! cuz head is nullptr now.
    
    return EXIT_SUCCESS; //from stdlib.h
}
