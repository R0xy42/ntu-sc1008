//
//  ShapeCollection.cpp
//  C++ Beginner
//
//  Created by Mars on 2026.04.19.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <type_traits>
using namespace std;

const double PI = 3.14159265358979;

class Shape {
protected:
    double area;

public:
    // TO-DO:
    // implement constructor
    Shape(){
        area = 0;
    }
    // implement virtual destructor
    virtual ~Shape(){}
    // implement pure virtual calArea()
    virtual void calArea() = 0; //pure virtual - abstract class
    // implement virtual string getType() const
    virtual string getType() const {
        return "Shape";
    }

    double getArea() const {
        return area;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    // TO-DO:
    // implement constructor
    Circle(double r) : radius(r){}
    // implement destructor
    ~Circle() override = default; // no raw pointer, so no need to do rule-of-three
    // override calArea()
    void calArea() override{
        area = PI * radius * radius;
    }
    // override getType() const
    string getType() const override {
        return "Circle";
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // TO-DO:
    // implement constructor
    Rectangle(double w, double h) : width(w) , height(h){}
    // implement destructor
    ~Rectangle() override = default;
    // override calArea()
    void calArea() override{
        area = width * height;
    }
    // override getType() const
    string getType() const override{
        return "Rectangle";
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    // TO-DO:
    // implement constructor
    Triangle(double b, double h): base(b), height(h){}
    // implement destructor
    ~Triangle() override = default; //子类的析构建议写上override
    // override calArea()
    void calArea() override{
        area = 0.5 * base * height;
    }
    // override getType() const
    string getType() const override{
        return "Triangle";
    }
};

int main() {
    cout << boolalpha;
    cout << "Is Shape abstract? " << is_abstract<Shape>::value << endl << endl;

    vector<Shape*> shapes; // shapes；存放着 Shape* 指针类型的变量。

    cout << "1) Create Circle" << endl;
    cout << "2) Create Rectangle" << endl;
    cout << "3) Create Triangle" << endl;
    cout << "4) Print Areas" << endl;
    cout << "5) Exit" << endl;

    int cmd;
    do {
        cout << "Enter command: " << endl;
        cin >> cmd;

        switch (cmd) {
        case 1: {
            double radius;
            cout << "Enter radius: " << endl;
            cin >> radius;
            shapes.push_back(new Circle(radius)); //new一个Circle类型的对象，用 radius来初始化。在堆上创建一个 Circle 对象，并==返回其地址！==
            //别忘了 new 是返回指针的（指向堆上的地址）
            //指针向上转型。
            break;
        }
        case 2: {
            double width, height;
            cout << "Enter width: " << endl;
            cin >> width;
            cout << "Enter height: " << endl;
            cin >> height;
            shapes.push_back(new Rectangle(width, height));
            break;
        }
        case 3: {
            double base, height;
            cout << "Enter base: " << endl;
            cin >> base;
            cout << "Enter height: " << endl;
            cin >> height;
            shapes.push_back(new Triangle(base, height));
            break;
        }
        case 4: {
            cout << endl;
            for (Shape* s : shapes)
                s->calArea();
            for (Shape* s : shapes) // 这里写得好！统一管理
                cout << s->getType() << " Area: " << s->getArea() << endl;
            cout << endl;
            break;
        }
        case 5:
            break;
        default:
            cout << "Unknown cmd: " << cmd << endl;
        }
    } while (cmd != 5);

    for (Shape* s : shapes)
        delete s; // one-by-one!

    //OOP, containers(vector)
    return 0;
}

//or:
//for(const auto& it : shapes){(*it)->calArea();} //it: iterator, object: *it
//since shapes is a vector container, it can use iterator;
//why we can (*it)-> : SO, (*it) is a Shape* object, so it's still a ==ptr==;
//we can access its member function through ptr->
