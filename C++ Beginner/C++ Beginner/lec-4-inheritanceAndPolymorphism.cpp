//
//  lec-4-inheritanceAndPolymorphism.cpp
//  C++ Beginner
//
//  Created by 邹嘉睿 on 2026.03.27.
//

#include <stdio.h>
#include <stdlib.h>
#include "ClassHelper.hpp"
#include "AnimalShelterManager.hpp"

using namespace std;


int main(void){
//    childA* c1 = new childA;
//    parent* p1 = new parent;
//    delete p1;
//    delete c1;
    
//    Hello from parent!
//    Hello from child!
//    Hello from parent!
//    parent EXIT
//    childA EXIT
//    parent EXIT
    //要创建子类对象，就要先创建父类对象！！！ 所以先进父类构造器，打印 hello from parent，随后有了父类对象创建子类，
    //再进子类构造器，hello from child。
    //再第二个是父类对象，直接Hello from parent。 随后执行完成后析构函数，像一个汉诺塔游戏，先放的在底下，所以后出。
    //最上面的是父类对象，因此最先调析构。 parent EXIT
    //然后是子类，子类析构。最后是子类依附的父类，析构。
    
    Animal* doggy = new Dog("Happy", 10, 1, 15.2);
    Dog* doggo = new Dog;
    
    doggy->displayInfo();
    doggy->setName("Fox");
    cout << "Dog's new name is \"" << doggy->getName() << "\"" << endl;
    doggy->speak();
    doggy->eat();
    doggy->move();
    doggy->move("Home!");
    
    doggo->setName("Forbes");
    doggo->move(108);
    
    Cat* cate = new Cat;
    cate->tailLength = 99.99; //可爱喵。
    
    cate->setName("🐱");
    string name = cate->Animal::getName();
    cout << name << "'s tail length is " << cate->tailLength << endl;
    
    Derived d;
    d.Base::show(3.14);
    d.Base::show(42);
    d.show(42);
    Base* b = &d; //pointer use -> !
    b->show(1); // int has override, dynamic binding gives Derived class's show function.
    b->Base::show(1); // manually choose function to use. No polymorphism involved.
    b->show(3.14); // Base's show function.
//    b->Derived::show(3.14) // compile error. Base type pointer b cannot see members in Derived class.
    
    
    return EXIT_SUCCESS;
}

