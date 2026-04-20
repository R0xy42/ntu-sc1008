//
//  1-3.cpp
//  C++ Beginner
//
//  Created by xxx on 2026.04.18.
//

#include <stdio.h>
#include <iostream>
using namespace std;

union Result {
    int mark;
    char grade; // Can be only 'A', 'B' or 'C'
};

struct Student {
    char studentName[50];
    bool isGrade;
    int finalMark; // Used to store the final mark
    Result res;

    void convertGrade() { // A=90 , B=80, C=60
        // TO-DO: Write your functions here
        //
        //
        //
        if(res.grade == 'A'){
            finalMark = 90;
        }else if(res.grade == 'B'){
            finalMark = 80;
        }else if(res.grade == 'C'){
            finalMark = 60;
        }else{
            finalMark = 0;
            cout << "Please be considerate!";
            return;
        }

    }
};

void displayStudentInfo(Student *students, int count) {
    // TO-DO: Write your functions here
    //
    //
    //
    double sum=0;
    cout << "Student Results: " << endl;
    for (int i=0; i<count; i++) {
        cout << "Name: " << students[i].studentName << ", Final Mark: " << students[i].finalMark << endl;
        sum += students[i].finalMark;
    }
    cout << endl;
    
    cout << "Average Final Mark: " << (sum/count) << endl;
    
}

int main() {
    // TO-DO: Write your functions here
    //
    //
    //
    cout << "How many students do you want to input?\n";
    cout << "Enter student size: ";
    int stuSize;
    cin >> stuSize;
    while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Invalid user input, please retry with a valid number.\n";
            cin >> stuSize;
            continue;
        }
        break;
    }
    
    int count=0;
    char gm = ' ';
    Student* stuList = new Student[stuSize];
//    string* stuName = new string[stuSize];
    while(count<stuSize){
        cin.get(); // 这一步很重要！没有这个 get，上次读stuSize成功后会有个newline烂在输入缓存区里！会导致下一次 stuName 直接被跳过了不读。
        cout << "Enter student name: ";
        cin.getline(stuList[count].studentName,1000);
        cout << "Enter 'G' if result is grade or 'M' if result is mark: ";
        cin >> gm;
        while(true){
            if(cin.fail()){
                cout << "..." << endl;
                cin.clear();
                cin.ignore(1000,'\n');
                cin >> gm;
                continue;
            }
            break;
        }
        
        switch (gm) {
            case 'G':
                cout << "Enter grade (A,B,C): ";
                cin >> stuList[count].res.grade;
                stuList[count].convertGrade();
                break;
            case 'M':
                cout << "Enter mark (0-100): ";
                cin >> stuList[count].res.mark;
                stuList[count].finalMark = stuList[count].res.mark;
                break;
            default: //守门，防坏人
                strcpy(stuList[count].studentName,"Screw YOU!");
                stuList[count].finalMark=0;
                break;
        }
        
        count++;
    }
    
    cout << endl;
    displayStudentInfo(stuList, stuSize);

    delete [] stuList;
    return 0;
}
