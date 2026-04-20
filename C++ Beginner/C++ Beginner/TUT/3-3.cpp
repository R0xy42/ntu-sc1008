//
//  3-3.cpp
//  C++ Beginner
//
//  Created by xxx on 2026.04.19.
//

#include <stdio.h>
#include <iostream>
#include <string>

class Pen {
private:
    std::string color;
    double price;

public:
    Pen(std::string initialColor, double initialPrice) {
        color = initialColor;
        price = initialPrice;
    }

    Pen& setColor(std::string newColor) {
        // TO-DO: Write your code here
        //
        if(!newColor.empty()){
            color = newColor;
        }
        return *this;
    }

    Pen& setPrice(double newPrice) {
        // TO-DO: Write your code here
        //
        if(newPrice>0){
            price = newPrice;
        }
        return *this;
    }// return a Pen& object! (pass reference), so that we can use .A().B().C() format.
//    Method Chaining
    void display() const { //声明为 const 是对的，display函数应该承诺不修改调用对象。
        // TO-DO: Write your code here
        //
        std::cout << "Pen Color: " << color << "\n";
        std::cout << "Price: $" << price << std::endl;
    }
};

int main() {
    // Creating a Pen object and using method chaining
    Pen myPen("Blue", 1.5);
    std::cout<< "The original color and price of the pen: " << std::endl;
    myPen.display();
    
    std::cout<< std::endl<<"The color and price of the pen after setting: " << std::endl;
    myPen.setColor("Red")
         .setPrice(2.0)
         .display();

    return 0;
}

