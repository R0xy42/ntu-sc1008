//
//  main.cpp
//  C++ Beginner
//
//  Created by 邹嘉睿 on 2026.03.11.
//

#include <iostream>
using namespace std;

inline double cube(double & a){return a = a * a * a;}
inline int defaultAdd(int a = 42, int b = 137){ return a+b;}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int number;
    cout << "please enter your input:\n";
    cin >> number;
    cout << "number is: " << number << endl;
    //向 cout 喊话，所以箭头指向 cout（或者可以把cout理解成出口，数据流从out流出，自然是指向cout）
    //从 cin 输入，所以箭头从 cin 向里指向。（把 cin 理解成数据流的入口，然后 箭头方向 为数据流的流向）
    
    bool tryCin = cin.fail();
    cout << "cin returns: " << tryCin << endl;
    
    double double_number_a;
    while(true){
        cout << "please enter a double type input:\n";
        cin >> double_number_a;
        
        if(!(cin.fail())){
            break;
        }
        
        cin.clear(); //清除失败状态
        cin.ignore(numeric_limits<streamsize>::max() , '\n');
        
        cout << "please give a valid input!\n";
        
    }
    
    cout << "your input is: " << double_number_a << endl;
    
    /* 内存管理 */
    double *dVar = new double;
    *dVar = 42.0;
    cout << "the value of this dVar is: " << *dVar << ", and its address is: " << dVar << endl;
    //1st: 0x6000005e8000
    //2nd: 0x6000027c0000
    //3rd: 0x600003928000
    //differenct!
    delete dVar;
    
    /* inline func 和 default args*/
    double a = 3.1415;
    a = cube(a);
    cout << "a is now: " << a << endl; //31.0035
    
    cout << "a + b = " << defaultAdd() << endl; //42+137
    cout << "42 + 42 = " << defaultAdd(42,42) << endl; //84;
    cout << "1 + b = " << defaultAdd(1) << endl; //1+137;
    //inline 真方便哇 ^_^
    
    double *p = nullptr; //use nullptr as default in C++!
    p = &a;
    cout << "*p = " << *p << endl;
    
    int *studentID = new int[20];
    
    delete[] studentID;
    
    return EXIT_SUCCESS;
}
