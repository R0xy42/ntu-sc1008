//
//  Q1.cpp
//  LAB
//
//  Created by 邹嘉睿 on 2026.03.19.
//

#include <iostream>
#include <limits>
#include <cstring>
using namespace std;
// Function to get a valid integer input
int getValidInt() {
    // TO-DO: WRITE Your code here
    int id;
    while(true){
        cin >> id;

        if(!(cin.fail())){
            cin.ignore(numeric_limits<streamsize>::max() , '\n');
            break;
        }

        cout << "Invalid input! Please enter an integer: " << endl;

        cin.clear();//clear stae flag
        cin.ignore(numeric_limits<streamsize>::max() , '\n');

    }
    
    return id;

}
// Function to get a valid float input
float getValidFloat() {
    // TO-DO: WRITE Your code here
    float idFloat;

    while(true){
        cin >> idFloat;

        if(!(cin.fail())){
            cin.ignore(numeric_limits<streamsize>::max() , '\n');
            break;
        }
        
        cout << "Invalid input! Please enter a valid float number: " << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max() , '\n');
    
    }

    return idFloat;
}
int main() {
    char name[50];  // Student name
    int studentID;  // Student ID
    float mathMark; // Math mark

    while (true) {
        // Get student name
        cout << "Enter student name (or enter '#' to exit):" << std::endl;
        cin.getline(name, 50);

        // Check if user wants to exit
        if (strcmp(name, "#") == 0) {
            break;
        }

        // Get student ID
        cout << "Enter student ID (integer):" << std::endl;
        studentID = getValidInt();

        // Get math mark
        cout << "Enter math mark (float):" << std::endl;
        mathMark = getValidFloat();

        // Display student information
        cout << "\nStudent Information:\n";
        cout << "Name: " << name << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Math Mark: " << mathMark << endl;
        cout << "-------------------------\n";
    }

    cout << "Program exited successfully." << endl;
    return 0;
}

//mad，为了把代码从 HackerEarth 粘贴出来可废了我一番力气。
//mark一下：审查 - network - AJAX/ - Payload

