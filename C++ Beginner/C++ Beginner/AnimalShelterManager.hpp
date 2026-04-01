//
//  AnimalShelterManager.hpp
//  C++ Beginner
//
//  Created by 邹嘉睿 on 2026.03.28.
//

#ifndef AnimalShelterManager_hpp
#define AnimalShelterManager_hpp

#include <stdio.h>
#include <string>

#define DEFAULT_NAME ""
#define DEFAULT_VALUE 0

using namespace std;

class Animal{
public:
    /* getter */
    string getName() const;
    int getId() const;
    int getAge() const;
    virtual string getTypeName() const;
    
    /* setter */
    bool setName(string newName);
    bool setAge(int newAge);
    
    
    virtual void speak();
    virtual void displayInfo() const;
    virtual void eat();
    
    void move() const;
    void move(string dest) const;

    
    /* constructor */
    Animal(){
        this->name = DEFAULT_NAME;
        this->id = DEFAULT_VALUE;
        this->age = DEFAULT_VALUE;
    }
    Animal(string newName, int newAge, int newId){
        this->name = newName;
        this->age = newAge;
        this->id = newId;
    }
    
    /* destructor */
    virtual ~Animal() = default;
    
protected:
    string name;
    int age;
    int id;
        
};

class Dog : public Animal{
public:
    using Animal::move;
    double weight;
    
    void speak() override;
    void displayInfo() const override;
    void eat() override;
    string getTypeName() const override;
    
    void fetch();
    
    void move(double speed) const;
    
    Dog(){
        this->name = DEFAULT_NAME;
        this->id = DEFAULT_VALUE;
        this->age = DEFAULT_VALUE;
        this->weight = DEFAULT_VALUE;
    };
    Dog(string newName, int newAge, int newId, double weight){
        this->name = newName;
        this->age = newAge;
        this->id = newId;
        this->weight = weight;
    }
    
    ~Dog() override = default;
};

class Cat : public Animal{
public:
    double tailLength;
    
    void speak() override;
    void displayInfo() const override;
    void eat() override;
    
    void scratch();
    
    ~Cat() override = default;
};

class Bird : public Animal{
public:
    void speak() override;
    void displayInfo() const override; //interpret const, override as "prefix" of this func
    void eat() override;
    
    void fly();
    
    ~Bird() override = default;
};

//函数声明可以只写类型啊。学到了
class Base {
public:
    virtual void show(int);
    void show(double);
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void show(int) override;
    void show(double);
    ~Derived() override = default;
};



#endif /* AnimalShelterManager_hpp */
