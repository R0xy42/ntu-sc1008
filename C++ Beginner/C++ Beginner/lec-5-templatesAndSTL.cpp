//
//  lec-5-templatesAndSTL.cpp
//  C++ Beginner
//
//  Created by 邹嘉睿 on 2026.04.09.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <iterator>
using namespace std;
//using std::cin;
//using std::cout;
//using std::endl;
//using std::vector;
//using std::list;
//using std::string;
//大项目就用啥导啥吧

// Function template
template <typename T>
void printData(T& a, T& b){
    cout << a << " and " << b << "\n";
}
template <typename T>
void mySwap(T& a, T& b){
    T temp = a; //since we access to a as a T type. just use T temp instead of T* temp;
    a = b;
    b = temp;
    printData(a, b);
}


// Class template with two parameters
template <class T1, class T2>
class Test {
    T1 a;
    T2 b;
public:
    Test(T1 x, T2 y) {
       a = x;
       b = y;
    }
    void show() {
       cout << a << " and " << b << endl;
    }
};

int main() {
    Test<float, int> test1(1.23, 123);
    Test<int, char> test2(100, 'W');
    test1.show();
    test2.show();
    //?可恶，Claude ocr的缩进在这里怎么不一样了。
    double a=3.14, b = 42;
    mySwap(a,b);
    
    
/* STL - vector */
    vector<string> strV;
    strV.push_back("meow");
    strV.push_back("123");
    strV.push_back("MyFirstVector!");
    
    for (int i=0; i<strV.size(); i++) {
        cout << strV[i] << " ";
    }
    cout << endl;
    
    vector<string>::iterator it;
    for (it = strV.begin(); it != strV.end(); ++it) {
        cout << *it << "\n";
    }
    
    
/* STL - list */
    list<double> dList;
    dList = {3.14,42,108.00,-1,2.718};
    cout << dList.size() << "\n";
    dList.sort();
    list<double>::iterator itlist;
    for (itlist = dList.begin(); itlist != dList.end(); ++itlist) {
        cout << *itlist << " ";
    }// -1 2.718 3.14 42 108, 升序排列
    cout << endl;
    
    while (!dList.empty()) {
        cout << dList.back() << " gone! remaining size: " << dList.size() - 1 << "\n";
        dList.pop_back();
    }
    dList.insert(itlist, 123);
    dList.push_front(420);
    
    list<double> lst = {24,1,3,0};
    dList.merge(lst);
    list<double>::iterator itl;
    for (itl = dList.begin(); itl != dList.end(); ++itl) {
        cout << *itl << " ";
    }
    dList.sort();
    cout << endl;
    for (itl = dList.begin(); itl != dList.end(); ++itl) {
        cout << *itl << " ";
    }
    cout << endl;
    
    list<double> lst2 = {2,4,6,8,10};
    lst2.swap(dList);
    for (itl = dList.begin(); itl != dList.end(); ++itl){
        cout << *itl << " ";
    }// 2 4 6 8 10
    cout << endl;
    cout << dList.size() << endl;
    
    dList.erase(dList.begin(),dList.end()); // erase all
    cout << dList.size() << endl;
    
    
/* STL - map */
    map<int,string> MyFirstMap;
    MyFirstMap[1] = "Hello!";
    MyFirstMap[2] = "Key2";
    MyFirstMap[3] = "Freedom!";
    
    int key = 2;
    auto itMap = MyFirstMap.find(key); //后悔了，it是个糟糕的命名决定。
    if(itMap != MyFirstMap.end()){
        cout << "Found! " << itMap->second << endl;
    }else{
        cout << "Key not found!\n";
    }
    
    for (itMap = MyFirstMap.begin(); itMap != MyFirstMap.end(); ++itMap) {
        cout << "Key " << itMap->first << " has value " << itMap->second << endl;
    }
    cout << "Size before erase: " << MyFirstMap.size() << endl;
    MyFirstMap.erase(MyFirstMap.begin(),next(MyFirstMap.begin(),2)); // 1,2步，3，但是前闭后开，所以移除前两个。
    cout << "Size after erase: " << MyFirstMap.size() << endl;
    cout << MyFirstMap.at(3) << endl; // return value at key=3; Attention! at(const key_type& key) return its value!

    MyFirstMap[1] = "To";
    
    for(const auto& m : MyFirstMap){
        cout << m.first << ": " << m.second << "\n";
    }// first, second;
    
    return 0;
}



