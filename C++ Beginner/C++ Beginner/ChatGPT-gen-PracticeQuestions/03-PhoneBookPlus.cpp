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
    string* note;
    int number;

public:
    // TO-DO: implement the constructor
    PhoneBook(): note(nullptr), number(0) {}
    
    //Rule-of-three
    //constructor
    PhoneBook(const string noteOfContacts[], int num) : note(nullptr) ,number(0){
        if(num > 0){
            number = num;
            note = new string[num];
            for (int i=0; i<num; i++) {
                note[i] = noteOfContacts[i];
            }
        }
    }
    
    //copy constructor
    PhoneBook(const PhoneBook& other) : contacts(other.contacts), number(0), note(nullptr) {
        note = new string[other.number];
        for (int i=0; i<other.number; i++) {
            note[i] = other.note[i];
        }
        number = other.number;
    }
    
    //operator=
    //return a Phonebook& type so that we can use a=b=c;
    PhoneBook& operator=(const PhoneBook& other){
        //node now nullptr, number now 0
        //This is NOT a constructor! We already have our object constructed here.
        
        if(this == &other){ // this: address, &other: address; other: obj
            return *this; //allowing self , a=a;
        }
                
        //new first, delete old then
        string* newNote = nullptr;
        //无论number是否大于0都应该赋值过去。 —— if 的范围；
        
//        1. 准备新资源
//        2. 删除旧资源
//        3. 更新 contacts
//        4. 更新 number
//        5. 更新 note
        
        if(other.number>0){
            newNote = new string[other.number];
            for (int i=0; i<other.number; i++) {
                newNote[i] = other.note[i];
            }
        }
        delete [] note; //删除旧资源
        
        //准备新资源
        number = other.number;
        note = newNote; // delete note address, free memory, and then assign newNote's address to variable note.
        contacts = other.contacts; // map真方便啊。直接内部写好了拷贝构造。
        return *this;
    }
    
    ~PhoneBook(){
        delete [] note;
    }
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
    
    /* Rule of three test */
    string notes[] = {"friend", "classmate", "robotics teammate"};

        PhoneBook pb1(notes, 3);
        pb1.addContact("Alice", "123");
        pb1.addContact("Bob", "456");

        cout << "pb1:" << endl;
        pb1.displayAllContacts();

        PhoneBook pb2 = pb1;   // copy constructor
        cout << "pb2 after copy construction:" << endl;
        pb2.displayAllContacts();

        PhoneBook pb3;
        pb3 = pb1;             // copy assignment
        cout << "pb3 after assignment:" << endl;
        pb3.displayAllContacts();

        pb3 = pb3;             // self-assignment
        cout << "pb3 after self-assignment:" << endl;
        pb3.displayAllContacts();

        PhoneBook empty;
        pb3 = empty;           // test assigning empty object
        cout << "pb3 after assigning empty PhoneBook:" << endl;
        pb3.displayAllContacts();


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
