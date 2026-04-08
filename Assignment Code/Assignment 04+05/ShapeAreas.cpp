//
//  ShapeAreas.cpp
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.04.04.
//

//int main(void){
//    cout << "PI: " << M_PI << endl;
//    return 0;
//} // used to test M_PI value;

#include <iostream>
#include <cmath>
#include <type_traits>
#include <vector>
using namespace std;

// Abstract base class
class Shape {
protected:
    double area; // 一个 protected 的area。需要 getter 访问。
public:
    // TO-DO: Please implement the constructor, the destructor and the calArea() function here
    //
    //
    // 一个纯虚的 calArea，方便子类两个形状自己写 override
    // Member function to get the area
    double getArea() const {
        return area;
    }

    Shape(){
        area = 0.0;
        cout << "Shape Constructor!" << endl;
    }
    virtual ~Shape(){
        cout << "Shape Destructor!" << endl;
    }

    virtual void calArea() = 0;
};
 
// Derived class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    // TO-DO: Please implement the constructor, the destructor and OVERRIDE the calArea() function here
    //
    //
    // : 冒号：拿到数据之后要干啥：
    Circle(double radius) : radius(radius){
        cout << "Circle Constructor!" << endl;
    }
    ~Circle() override{
        cout << "Circle Destructor!" << endl;
    }

    void calArea() override {
        area = M_PI * radius * radius;
    }
 
};
 
// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    // TO-DO: Please implement the constructor, the destructor and OVERRIDE the calArea() function here
    //
    //
    Rectangle(double width, double height) : width(width), height(height){
        cout << "Rectangle Constructor!" << endl;
    }
    ~Rectangle() override {
        cout << "Rectangle Destructor!" << endl;
    }

    void calArea() override {
        area = height * width;
    }

};

int main() {
    cout << boolalpha;
    cout << "Is Shape abstract? " << is_abstract<Shape>::value << endl << endl;
 
    vector<Shape*> shapes;
 
    cout << "1) Create Circle" << endl;
    cout << "2) Create Rectangle" << endl;
    cout << "3) Print Areas" << endl;
    cout << "4) Exit" << endl;
 
    int cmd;
    do {
        cout << "Enter command: " << endl;
        cin >> cmd;
 
        switch (cmd) {
        case 1: {
            double radius;
            cout << "Enter radius: " << endl;
            cin >> radius;
            shapes.push_back(new Circle(radius));
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
            cout << endl;
            for (Shape* s : shapes)
                s->calArea();
            for (Shape* s : shapes)
                cout << "Area: " << s->getArea() << endl;
            cout << endl;
            break;
        }
        case 4:
            break;
        default:
            cout << "Unknown cmd: " << cmd << endl;
        }
    } while (cmd != 4);
 
    for (Shape* s : shapes)
        delete s;
 
    return 0;
}
