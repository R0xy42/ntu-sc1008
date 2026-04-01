//
//  Q1.cpp
//  LAB
//
//  Created by 邹嘉睿 on 2026.03.31.
//

#include <stdio.h>
#include <iostream>
using namespace std;
class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r, double i) : real(r), imag(i) {}

    // Overloading the + operator
    // TODO: Write Your Code Here
    
    Complex operator+(const Complex& c1) const {
        return Complex(real+c1.real, imag+c1.imag);
    }

    // Overloading the - operator
    // TODO: Write Your Code Here
    //
    // ？这个黑粗体是怎么做到的？
    Complex operator-(const Complex& c1) const { //use & to pass reference, instead of copying the object.
        return Complex(real-c1.real, imag-c1.imag);
    }
    
    // Overloading the << operator for output
    friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
        // TODO: Write Your Code Here
        //
        //
        //view the output stream as a flow~
        
        if(c.imag<0){
            out << c.real << " - " << -c.imag << "i";
        }else{
            out << c.real << " + " << c.imag << "i";
        }
        return out;
    }
};
int main() {
    double d1, d2;

    cout << "Enter first complex number:" << endl;
    cin >> d1 >> d2;
    Complex c1(d1, d2);

    cout << "Enter second complex number:" << endl;
    cin >> d1 >> d2;
    Complex c2(d1, d2);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    return 0;
}
