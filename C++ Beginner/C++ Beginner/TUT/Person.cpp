#include "Person.h"
#include <iostream>
using namespace std;

// TODO: Implement Person class constructor and function here
Person::Person(string n, int a) {
    // TODO: Initialize member variables
    //
    name = n;
    age = a;
}

void Person::displayInfo() const {
    // TODO: Display person's details
    //
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << endl;

}
