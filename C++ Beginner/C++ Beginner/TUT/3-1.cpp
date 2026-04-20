//
//  3-1.cpp
//  C++ Beginner
//
//  Created by xxx on 2026.04.18.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Student {
private: // TODO: define the private members here
    string name;
    int age;
    double gpa;

public:
    // Constructor
    Student(std::string studentName, int studentAge, double studentGPA) {
        // TODO: Define the constructor
        name = studentName;
        age = studentAge;
        gpa = studentGPA;
    }

    // Display function
    void displayDetails() const {
        std::cout << "Student Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "GPA: " << gpa << std::endl;
    }

    // Getters
    // TODO: Implement the getters here
    string getName() const{
        return name;
    }
    int getAge() const{
        return age;
    }
    double getGPA() const{
        return gpa;
    }

    // Setters
    // TODO: Implement the setters here
    bool setName(const string& s){
        if(!s.empty()){
            name = s;
            return 1;
        }
        return 0;
    }
    
    bool setAge(const int& stuAge){
        if(stuAge > 0 && stuAge < 120){
            age = stuAge;
            return age;
        }
        return 0;
    }
    
    bool setGPA(const double stuGPA){
        if(stuGPA>=0.0 && stuGPA <= 5.0){ //xs，忘记NTU是 5.0 制了。
            gpa = stuGPA;
            return 1;
        }
        return 0;
    }
    
};

int main() {
    // Creating Student objects
    Student student1("Alice", 20, 3.8);
    Student student2("Charlie", 19, 3.5);

    // Display details of students
    std::cout << "Initial Student Details:\n";
    student1.displayDetails();
    std::cout << std::endl;
    student2.displayDetails();
    std::cout << std::endl;

    // Modify student1 details using setters
    student1.setName("Bob");
    student1.setAge(22);
    student1.setGPA(3.9);

    // Display updated details
    std::cout << "Updated Student Details:\n";
    student1.displayDetails();

    return 0;
}
