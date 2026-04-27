//
//  MergeSortedArrays.cpp
//  C++ Beginner
//
//  Created by Mars on 2026.04.19.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

// TO-DO:
// Write a template function mergeSortedArrays() that merges two sorted arrays
// arr1 with size1 and arr2 with size2 into a new sorted dynamic array mergedArr.
// The mergedArr pointer must be updated through reference.

template <class T>
void mergeSortedArrays(T* arr1, int size1, T* arr2, int size2, T*& mergedArr) {
    // Write your code here
    // bubble?
    mergedArr = new T(size1+size2);
    
    for (int i=0; i<size1; i++) {
        mergedArr[i] = arr1[i];
    }
    for (int i=0; i<size2; i++) {
        mergedArr[i+size1] = arr2[i];
    }
    
    int size = size1+size2;
    
//    sort(it1,it2); // introsort, very powerful
    
    // Bubble sort.
    for (int i=0; i<size; ++i) {
        bool swapped = false; // inner loop optimization
        for (int j=0; j<size-i-1; ++j) {
            if(mergedArr[j] > mergedArr[j+1]){
                swap(mergedArr[j],mergedArr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){ // no swap this turn -- sorted!
            break;
        }
    }
    
}

// TO-DO:
// Write a template function printAndDeallocate() that
// 1. prints the merged array in one line
// 2. deallocates it using delete[]

template <class T>
void printAndDeallocate(T* mergedArr, int size) {
    // Write your code here
    for (int i=0; i<size; i++) {
        cout << mergedArr[i] << " ";
    }
    cout << endl;
    delete[] mergedArr;
}

int main() {
    cout << "1) Merge Sorted Arrays" << endl;
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
            int* arr1 = new int[size1];
            cout << "Enter elements of first sorted array: " << endl;
            for (int i = 0; i < size1; i++)
                cin >> arr1[i];

            cout << "Enter size of second array: " << endl;
            cin >> size2;
            int* arr2 = new int[size2];
            cout << "Enter elements of second sorted array: " << endl;
            for (int i = 0; i < size2; i++)
                cin >> arr2[i];

            int* mergedArr = nullptr;
            mergeSortedArrays(arr1, size1, arr2, size2, mergedArr);
            printAndDeallocate(mergedArr, size1 + size2);

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
