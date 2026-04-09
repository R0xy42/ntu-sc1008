//
//  Phonebook.cpp
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.04.09.
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

#include <iterator>
class PhoneBook {
private:
    map<string, string> contacts; // Maps names to phone numbers
public:
    // TO-DO: Implement the constructor
    //
    PhoneBook() = default;
    // TO-DO: Implement addContact(const string &name, const string &number)
    //
    void addContact(const string &name, const string number){
        //emplace.. nvm
        contacts[name] = number;
    }
    // TO-DO: Implement removeContact(const string &name)
    //
    void removeContact(const string &name){
        // if(contacts.empty()){
        //     return;
        // }
        // map<string,string>::iterator itMap = contacts.find(name);
        // if(itMap != contacts.end()){ // found
        //     contacts.erase(name);
        // }else{
        //     return;
        // }
        contacts.erase(name);
    }

    // TO-DO: Implement findContact(const string &name)
    //
    string findContact(const string& name){ //name can't be changed
        auto iM = contacts.find(name);
        if(iM == contacts.end()){
            return "Not Found!";
        }
        return iM->second;
    }
    // TO-DO: Implement displayAllContacts()
    //
    void displayAllContacts() const {
        if(contacts.empty()){
            return;
        }
        for(const auto& iM : contacts){
            cout << iM.first << " -> " << iM.second << endl;
        }
    }

};

int main() {
    PhoneBook pb;
 
    cout << "1) Add Contact" << endl;
    cout << "2) Remove Contact" << endl;
    cout << "3) Find Contact" << endl;
    cout << "4) Display All Contacts" << endl;
    cout << "5) Exit" << endl;
 
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
        case 4: {
            cout << "All Contacts:" << endl;
            pb.displayAllContacts();
            break;
        }
        case 5:
            break;
        default:
            cout << "Unknown cmd: " << cmd << endl;
        }
    } while (cmd != 5);
 
    return 0;
}
