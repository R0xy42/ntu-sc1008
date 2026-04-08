//
//  Q1.cpp
//  LAB
//
//  Created by 邹嘉睿 on 2026.04.08.
//

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
using namespace std;

class PatientQueue {
private:
    /* 一道用来学习 list链表 的lab题。头插、遍历、头删、查空。*/
    /* 以及，成员变量依旧声明为 private，这里已经用了 std 可以简写为 list<string> queue;*/
    std::list<std::string> queue; // Stores patient names
public:
    // Constructor: Initializes an empty patient queue
    PatientQueue() : queue() {}
    ~PatientQueue(){}
    // TO-DO 1: Implement the function addPatient to add a new patient's name to the end of the queue
    //
    void addPatient(const std::string& name){
        queue.push_back(name);
    } //add a member at the end of queue
    //push_front

    // TO-DO 2: Implement the function servePatient: removes and returns the patient at the front of the queue
    // If the queue is empty, returns a reminder message
    //
    string servePatient(){
        if(queue.empty()){
            return "Empty queue!";
        }//check for empty list
        string front = queue.front(); //get front name
        queue.pop_front(); //remove front name
        return front; // similarly, queue.back();  queue.pop_back();
        //It's dangerous to use these two on empty list, so check for empty list first.
    }


    // TO-DO 3: Implement the function isEmpty
    //
    bool isEmpty() const {//const承诺不修改传入对象
//        if(queue.empty()){
//            return 1;
//        }
//        return 0;
        return queue.empty(); //更直接。
    }

    // TO-DO 4: Implement the function displayQueue to print out all patients in order
    //
    void displayQueue() const { //same here
        for(const std::string& s : queue){ // why like this?
            cout << s << " ";
        }
        cout << "\n";
    }

};

int main() {
    PatientQueue clinicQueue;

    cout << "1) Add patient" << endl;
    cout << "2) Display queue" << endl;
    cout << "3) Check queue" << endl;
    cout << "4) Serve patient" << endl;
    cout << "5) Exit" << endl;

    int cmd;
    do {
        cout << "Enter command: " << endl;
        cin >> cmd;
        switch(cmd) {
        case 1:
            {
                string value;
                cin >> value;
                clinicQueue.addPatient(value);
            }
            break;
        case 2:
            clinicQueue.displayQueue();
            break;
        case 3:
            if (clinicQueue.isEmpty()) {
                cout << "No patient in the queue now" << endl;
            } else {
                cout << "There are still patient in the queue now" << endl;
            }
            break;
        case 4:
            cout << "Serving patient: " << clinicQueue.servePatient() << endl;
            break;
        case 5:
            break;
        default:
            cout << "Unknown cmd: " << cmd << endl;
        }
    } while (cmd != 5);

    return 0;
}
