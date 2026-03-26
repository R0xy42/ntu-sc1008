//
//  NodeHelper.hpp
//  C++ Beginner
//
//  Created by 邹嘉睿 on 2026.03.26.
//

#ifndef NodeHelper_hpp
#define NodeHelper_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

struct Node {
    double id;
    string name;
    Node* nextNode;
};

void insertNodeAtEnd(Node*& head, double new_id, string new_str);

void printList(Node* head);

void printId(Node* head);

void deleteNode(Node*& head, double node_id);

void deleteList(Node*& head);


#endif /* NodeHelper_hpp */
