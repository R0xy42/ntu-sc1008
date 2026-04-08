//
//  MergeArrays.cpp
//  Assignment Code
//
//  Created by 邹嘉睿 on 2026.04.04.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


////// To-do: Write Your Code Here//////////////
// Template function mergeArrays() to merge two arrays
//
//
template<class Any>
void mergeArrays(Any* arr1, int size1, Any* arr2, int size2, Any*& mergedArr){
    if(arr1 == nullptr || arr2 == nullptr){
        if(arr1 == nullptr){mergedArr = arr2;}
        if(arr2 == nullptr){mergedArr = arr1;}
    }
    //attention! 必须用 *& 才能改到外面的指针！否则只是改指针的拷贝。不能改外面指针的指向。

    Any* concatArr = new Any[size1+size2]; //without [], it's just a Any object, not an Any array!
    for(int i=0; i<size1; i++){
        concatArr[i] = arr1[i];
    }
    for(int i=0; i<size2; i++){
        concatArr[size1+i] = arr2[i];
    }
    mergedArr = concatArr;
}
////// To-do: Write Your Code Here//////////////
// Template function printAndDeallocate() to print and deallocate the merged array
//
//
template<class Any>
void printAndDeallocate(Any* mergedArray, int size){
    cout << "Merged Array: ";
    for(int i=0; i<size; i++){
        cout << mergedArray[i] << " ";
    }
    cout << endl;
    delete [] mergedArray;
}


int main() {
    cout << "1) Merge Arrays" << endl;
    cout << "2) Exit" << endl;
 
    int cmd;
    do {
        cout << "Enter command: " << endl;
        cin >> cmd;
 
        switch (cmd) {
        case 1: {
            int size1, size2;
            cout << "Enter size of first array: " << endl;
            cin >> size1;
            double* arr1 = new double[size1];
            cout << "Enter elements of first array: " << endl;
            for (int i = 0; i < size1; i++)
                cin >> arr1[i];
 
            cout << "Enter size of second array: " << endl;
            cin >> size2;
            double* arr2 = new double[size2];
            cout << "Enter elements of second array: " << endl;
            for (int i = 0; i < size2; i++)
                cin >> arr2[i];
 
            double* mergedArray = nullptr;
            mergeArrays(arr1, size1, arr2, size2, mergedArray);
            printAndDeallocate(mergedArray, size1 + size2);
 
            delete[] arr1;
            delete[] arr2;
            break;
        }
        case 2:
            break;
        default:
            cout << "Unknown cmd: " << cmd << endl;
        }
    } while (cmd != 2);
 
    return 0;
}
