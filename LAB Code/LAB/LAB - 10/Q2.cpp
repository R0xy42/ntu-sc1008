//
//  Q2.cpp
//  LAB
//
//  Created by 邹嘉睿 on 2026.04.08.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
// Base class: Sports
class Sports {
protected:
    string sport; // sport name
public:
    // TO-DO 1: Implement the constructor and descructor
    //
    Sports(string s): sport(s){
        cout << "Sports constructor!" << endl;
    }
//    Sports() = default;
    ~Sports(){
        cout << "Sports destructor!" << endl;
    }

    // Display sports information
    void displaySports() const {
        cout << "Sport: " << sport << endl;
    }
};

// Base class: Academics
class Academics {
protected:
    float gpa; // GPA
public:
    // TO-DO 2: Implement the constructor and destructor
//
    Academics(float gpa) : gpa(gpa){
        cout << "Academics constructor!" << endl;
    }
//    Academics() = default;
    ~Academics(){
        cout << "Academics destructor!" << endl;
    }

    // Display academic information
    void displayAcademics() const {
        cout << "GPA: " << gpa << endl;
    }
};

// TO-DO 3: Implement the Derived class: StudentAthlete, which inherits from both Academics and Sports

class StudentAthlete : public Sports, public Academics{
private:
    string name;
    int age;
    int studentID;

public:
    StudentAthlete(string s, float g,string n, int a, int id): Sports(s), Academics(g),name(n),age(a), studentID(id){
        cout << "StudentAthlete constructor!" << endl;
    }
    ~StudentAthlete(){
        cout << "StudentAthlete destructor!" << endl;
    }

    void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age << ", Student ID: " << studentID << endl;
        cout << "Sport: " << sport << endl;
        cout << "GPA: " << gpa << endl;
    }


};

int main() {
    cout << "Enter name, age, student ID, sports, and GPA:" << endl;

    string name, sports;
    int age, id;
    float gpa;

    cin >> name >> age >> id >> sports >> gpa;

    //Create a StudentAthlete instance
    StudentAthlete stu(sports, gpa, name, age, id);

    // Display all the information
    cout<<endl;
    stu.displayInfo();
    cout<<endl;
    
    // Test code to demonstrate multiple inheritances
    stu.displaySports();
    stu.displayAcademics();
    cout<<endl;
    
    return 0;
}
//构造的顺序：Sports、Academics、StudentAthlete
//是因为继承时声明顺序是先Sports后Academics。跟着声明顺序走的！和初始化列表顺序无关
//析构的顺序是：StudentAthlete、Academics、Sports
//先进后出，开在 Stack 上。

//display 相关的函数，因为不修改传入内容，都应该声明为 const 承诺！
