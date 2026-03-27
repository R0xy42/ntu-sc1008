
//  NodeHelper.cpp
//  C++ Beginner
//
//  Created by 邹嘉睿 on 2026.03.26.
//

#include "NodeHelper.hpp"

using namespace std;

void insertNodeAtEnd(Node*& head, double new_id, string new_str){
    //1. find the last node
    //2. add a node
    //3. make the new node's ptr pointing to nullptr;
    
    Node* newNode = new Node;
    newNode->nextNode = nullptr;
    newNode->name = new_str;
    newNode->id = new_id;
    
    
    if(head == nullptr){
        //list is empty
        head = newNode;
    }else{
        //newNode is our new node.
        //we pass values to add a new node at the end of this list
        //we always pass the head address of a list in.
        Node* temp = head;
        while(temp->nextNode != nullptr){
            temp = temp->nextNode; //不断找下一个 node
        }
        //chained! 自己是自己的头，也是上一个节点的尾，自己带着下一个节点的头。
        //在temp指向最后一个node 的时候跳出循环。
//        temp = newNode;
        //所以这里应该是用 temp 的next node 来记住newnode，而不是temp
        temp->nextNode = newNode;
        
    }
    //delete newNode;
    //这句会让里面的内容被删除，变成垃圾值。
}


void insertNodeAtPos(Node*& head, double new_id, string new_str, int pos){
    //locate pos, traverse
    //say, pos = 3, then it should be the 3rd node after insertion, means we stop at n=2
    //need previousPtr to memorize last node, and a nextPtr to memorize the future one.
    //so, nextPtr = nodePtr->next.
    //update nodePtr with new one
    //then make nodePtr->next = nextPtr, previousPtr->next = nodePtr
    
    Node* insertNode = new Node;
    insertNode->name = new_str;
    insertNode->id = new_id;
    insertNode->nextNode = nullptr;
    
    
    //handle invalid input:
    if(pos <= 1){
        //insert at the head; but I want to curse this f-word user first.
        cout << "Insert at the first node" << endl;
        Node* temp = head;
        head = insertNode;
        insertNode->nextNode = temp;
        return;
    }
    //handle empty list:
    if(head == nullptr){
        head = insertNode;
        cout << "Empty List! Node can only be inserted as the first node." << endl;
        return;
    }
    
    
    Node* previousPtr = nullptr;
    Node* currPtr = head;
    int count = 0;
    while(currPtr != nullptr && count != (pos-1)){ //我们总是让当前的 ptr 不为nullptr，这样可以走到最后一步。
        previousPtr = currPtr;
        currPtr = currPtr->nextNode;
        count++;
    }
    if(currPtr == nullptr){//oops,这里 currentPtr 已经指向 nullptr了，所以没法访问 nextNode，直接改成 currPtr 就好了。
        cout << "Position out of list! Insert at the end." << endl;
    }
    
    previousPtr->nextNode = insertNode;
    insertNode->nextNode = currPtr;
    
}


void printList(Node* head){
    //print out the entire list, stop when meet a nullptr;
    //using while loop
    if(head == nullptr){cout << "Empty List!\n";}
    
    int count = 1;
    while(head != nullptr){
        cout << "This is node " << count << endl;
        cout << "node " << count << "'s id is: " << head->id << endl;
        cout << "node " << count << "'s name is: " << head->name << endl;
        head = head->nextNode; //记得更新链表的index到下一个node去啊！！！
        count++;
    }

}

void printId(Node* head){
    Node* curr = head;
    while(curr != nullptr){
        cout << curr->id << " -> ";
        curr = curr->nextNode;
    }
    cout << "NULL" << endl;
}

void deleteNode(Node*& head, double node_id){
    //1、empty list
    //2、head node
    //3、not head node
    if(head == nullptr){
        cout << "Empty List! Nothing to delete!\n";
        return;
    }
    
    if(fabs(head->id - node_id) < 1e-8){
        //2, head node
        Node* nodePtr = head; //release head, and memorize head address
        head = head->nextNode; //skip head node;
        delete nodePtr; // free this address;
        nodePtr = nullptr; //why do we need this?????
    }else{
        //3, not head node
        Node* nodePtr = head;
        Node* previousNodePtr = nullptr; //不要连着写！好像会出 bug，no viable overload
        while(nodePtr != nullptr && fabs(nodePtr->id - node_id) > 1e-8){ //protection, 2 wont proceed if cond 1 is false
            previousNodePtr = nodePtr;
            nodePtr = nodePtr->nextNode;
        }
        //现在退出循环了，找到了 —— nodePtr是要删除的。
        if(nodePtr != nullptr){
            previousNodePtr->nextNode = nodePtr->nextNode; //这里两个都要next！因为previous的next是指向下一个的
            //如果previous 不next，就是把previous自己的node改成索引向nodenext了，而且previous 的next依旧没改。报错。
            delete nodePtr;
            nodePtr = nullptr;
        }
        
    }
    
}

void deleteList(Node*& head){
    Node* nodePtr = head; //因为head也要删除，但是得先保护结构，所以先用别的变量来traverse。
    Node* rubbishPtr = nullptr;
    
    while(nodePtr != nullptr){
        rubbishPtr = nodePtr;
        nodePtr = nodePtr->nextNode;
        delete rubbishPtr;
        rubbishPtr = nullptr;
    }
    head = nullptr; //最后把 head 也改成null
} // do remember we need to traverse the whole list to delete!
