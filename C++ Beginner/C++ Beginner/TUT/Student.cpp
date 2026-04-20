#include "Student.h"
#include <iostream>
using namespace std;

// TODO: Implement Student class constructor and initialize studentID 
Student::Student(string n, int a, int id)
    : Person(n, a) { // partially initialized with parameters list~
        studentID = id;
}

void Student::displayInfo() const {
    // TODO: Output Student Information
    //
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "ID: " << studentID << endl;

}
