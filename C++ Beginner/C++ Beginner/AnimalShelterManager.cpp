//
//  AnimalShelterManager.cpp
//  C++ Beginner
//
//  Created by 邹嘉睿 on 2026.03.28.
//

#include "AnimalShelterManager.hpp"
#include <iostream>

using namespace std;

/* getter */
string Animal::getName() const {
    return this->name;
}
int Animal::getId() const {
    return this->id;
}
int Animal::getAge() const {
    return this->age;
}
string Animal::getTypeName() const {
    return "Animal";
}

/* setter */
bool Animal::setName(string newName){
    if(name.empty() || name != newName){
        this->name = newName;
        return 1;
    }
    return 0;
}
bool Animal::setAge(int newAge){
    if(newAge>0){
        this->age = newAge;
        return age;
    }
    return 0;
}

void Animal::speak(){
    cout << "Animal can't speak" << endl;
}

void Animal::displayInfo() const{
//    cout << "Current static type is: " << typeid(this).name() << ", and current actual type is: " << typeid(*this).name() << endl;
    cout << "Current name: " << this->name << endl;
    cout << "Current dynamic type: " << typeid(*this).name() << endl;
}

void Animal::eat(){
    cout << "We ate a lot today~" << endl;
}

void Animal::move() const {
    cout << "Animal on the move!" << endl;
}

void Animal::move(string dest) const{
    cout << "Animals have moved to " << dest << endl;
}

string Dog::getTypeName() const{
    return "Dog";
}

void Dog::speak(){
    cout << "Barking~~~~~~" << endl;
}

void Dog::displayInfo() const{
    cout << "This dog's current type is " << Dog::getTypeName() << ", and its static type is " << Animal::getTypeName() << endl;
    if(!name.empty() && id){
        cout << "This dog's name is " << this->name << ", with id " << this->id << endl;
    }
    if(fabs(weight-0.0) > 1e-8){
        cout << "Its weight is: " << weight << endl;
    }
}

void Dog::eat(){
    cout << "Hungry! Dog eats!" << endl;
}

//void Dog::fetch();//Out-of-line declaration of a member must be a definition

void Dog::fetch(){
    cout << "Fetch! Nice Catch!" << endl;
}

void Dog::move(double speed) const{
    cout << name << " is moving at a very high speed of "<< speed << " km/h !" << endl;
}

void Cat::speak(){
    cout << "Meow~~~~~~" << endl;
}

void Cat::displayInfo() const{
    cout << "This cat's name is " << name << ", with id " << id << endl;
    cout << "Its tail length is: " << tailLength << endl;
}

void Cat::eat(){
    cout << "Cat is eating!" << endl;
}

void Cat::scratch(){
    cout << "Scratch scratch!" << endl;
}


/* ----- Base & Derived Test on function hiding ----- */
void Base::show(int a){
    cout << "Base int: " << a << endl;
}

void Base::show(double a){
    cout << "Base double: " << a << endl;
}

void Derived::show(int a){
    cout << "Derived int: " << a << endl;
}

void Derived::show(double a){
    cout << "Derived double: " << a << endl;
}
/* ----- Base & Derived Test END----- */
