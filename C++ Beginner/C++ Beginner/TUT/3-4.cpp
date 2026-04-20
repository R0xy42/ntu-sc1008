//
//  3-4.cpp
//  C++ Beginner
//
//  Created by xxx on 2026.04.19.
//

#include <stdio.h>
#include <iostream>

class Box {
private:
    double length;
    double width;
    double height;

public:
    // Constructor to initialize the box dimensions
    Box(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }

    // Member function that can access the private members
    void calculateVolume() {
        // Caclulate and display the volume of the box
        // TODO: Write your code here
        //
        std::cout << "Box Volume: " << (length*width*height) << " cubic units" << std::endl;

    }

    // Declare a friend function to display private members
    // TODO: Write your code here
    //
    friend void displayDimensions(const Box &b);//承诺不修改传入的对象
    // friend 声明只能在类里面写！！
};


// Define the friend function (that can access private members of Box)
// TODO: Write your code here
//
void displayDimensions(const Box &b){ //承诺不修改传入的对象
    //因为不是成员函数，所以不能加 const 在后面！因为根本没有“调用对象”一说。
    std::cout << "Box Dimensions: \n";
    std::cout << "Length: " << b.length << std::endl;
    std::cout << "Width: " << b.width << std::endl;
    std::cout << "Height: " << b.height << std::endl;
}

int main() {
    // Creating a Box object
    Box myBox(5.0, 3.0, 2.0);

    // Friend function accessing private data
    displayDimensions(myBox);

    // Member function accessing private data
    myBox.calculateVolume();

    return 0;
}
