//
//  3-2.cpp
//  C++ Beginner
//
//  Created by xxxon 2026.04.18.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class VisitorCounter {
private:
    int* count;  // Pointer to dynamically allocated memory for visit count

public:
    VisitorCounter(int initialCount) {
        count = new int(initialCount);
        cout << "Constructor called with the count as " << *count << endl;
    }

    ~VisitorCounter() {
        cout << "Destructor called with the count being " << *count << endl;
        delete count; // 要手动释放内存。
    }

    void increment() {
        (*count)++;
    }

    void display() const {
        cout << "Visitor Count: " << *count << endl;
    }
    
    VisitorCounter(const VisitorCounter& vc): count(new int(*vc.count)){ // 表示 新建一块内存，然后初始化为 *vc.count
        //        count = new int;
        //        *count = *vc.count; // copy constructor
    }
    // do remember that count is a pointer, so use deferencing!
    
};

int main() {
    VisitorCounter counter(10);
    cout << "\nOriginal Counter:\n";
    counter.display();

    // Copy the counter
    VisitorCounter counterCopy = counter;
    cout << "counterCopy:\n";
    counterCopy.display();

    // Increase copied object's count
    counterCopy.increment();
    counterCopy.increment();
    cout << "\nAfter modifying copied counter...\n";
    cout << "Original Counter: "<<endl;
    counter.display();
    cout << "counterCopy: "<<endl;
    counterCopy.display();
    cout <<endl <<endl;

    return 0;
}
