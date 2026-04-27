//
//  03-PhoneBookPlus.cpp
//  C++ Beginner
//
//  Created by Mars on 2026.04.19.
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

class PhoneBook {
private:
    map<string, string> contacts;

public:
    // TO-DO: implement the constructor
    PhoneBook(){}
    // TO-DO: implement addContact(const string& name, const string& number)
    void addContact(const string& name, const string& number){//const cuz we dont modify it
        contacts[name] = number;
    }
    // TO-DO: implement removeContact(const string& name)
    void removeContact(const string& name){
        contacts.erase(name);
    }
    // TO-DO: implement findContact(const string& name) const
    // return the number if found, otherwise return "Not Found!"
    string findContact(const string& name) const {
        auto it = contacts.find(name);
        if(it == contacts.end()){
            //not found, and end() is the element behind the last element!
            //it's a sentinel value; one should never use end()->second;
            return "Not Found!";
        }else{
            return it->second;
        }
    }
    // TO-DO: implement displayAllContacts() const
    void displayAllContacts() const{
        auto it = contacts.begin();
        for (it = contacts.begin(); it!=contacts.end(); ++it) {
            cout << "Name: " << it->first << ", number: " << it->second << "\n";
        }
    }
    // TO-DO: implement displayContactsByPrefix(const string& prefix) const
    // print only contacts whose names start with prefix
    // if no match exists, print: No matched contact.
    void displayContactsByPrefix(const string& prefix) const {
        //start with prefix!
        //string match. starts_with
        bool matchFlag = false;
        auto it = contacts.begin();
        for (it=contacts.begin(); it!=contacts.end(); ++it) {
            if(it->first.starts_with(prefix)){ //唔姆
                //这里 starts_with(const type xx) 是C++20 的函数啊
                //之前的可以：if (it->first.rfind(prefix, 0) == 0)
//                "Alice".rfind("li", 0) == 0   // false
//                so ==0 means found;
                matchFlag = true;
                cout << "Name: " << it->first << ", number: " << it->second << "\n";
            }
        }
        if(!matchFlag){
            cout << "No matched contact." << endl;
        }
    }
};

int main() {
    PhoneBook pb;

    cout << "1) Add Contact" << endl;
    cout << "2) Remove Contact" << endl;
    cout << "3) Find Contact" << endl;
    cout << "4) Display All Contacts" << endl;
    cout << "5) Display Contacts By Prefix" << endl;
    cout << "6) Exit" << endl;

    int cmd;
    do {
        cout << "Enter command: " << endl;
        cin >> cmd;

        switch (cmd) {
        case 1: {
            string name, number;
            cout << "Enter name: " << endl;
            cin >> name;
            cout << "Enter number: " << endl;
            cin >> number;
            pb.addContact(name, number);
            break;
        }
        case 2: {
            string name;
            cout << "Enter name: " << endl;
            cin >> name;
            pb.removeContact(name);
            break;
        }
        case 3: {
            string name;
            cout << "Enter name: " << endl;
            cin >> name;
            cout << "The contact number of " << name << ": " << pb.findContact(name) << endl;
            break;
        }
        case 4:
            cout << "All Contacts:" << endl;
            pb.displayAllContacts();
            break;
        case 5: {
            string prefix;
            cout << "Enter prefix: " << endl;
            cin >> prefix;
            pb.displayContactsByPrefix(prefix);
            break;
        }
        case 6:
            break;
        default:
            cout << "Unknown cmd: " << cmd << endl;
        }
    } while (cmd != 6);

    return 0;
}
