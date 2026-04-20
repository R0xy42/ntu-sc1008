//
//  4-3.cpp
//  C++ Beginner
//
//  Created by xxx on 2026.04.19.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
#include <numeric>   // for std::accumulate

using namespace std;
int main() {
    // Declare a vector to store daily sales.
    std::vector<int> dailySales;
    
    //so basically container vector is a resizable array, an array that can be dynamically changed.
    //std::list: doubly-linked list
    //std::map: key-value pair
    
    // TO-DO: Add seven daily sales values to the vector:
    //         120, 200, 150, 80, 90, 220, 100
    //
    //
    dailySales = {120, 200, 150, 80, 90, 220, 100}; // use braces!

    // TO-DO: Print all sales values by using an iterator
    //
    //
    double sum=0;
    vector<int>::iterator it = dailySales.begin();
    for (it = dailySales.begin(); it != dailySales.end(); ++it) {
        cout << *it << " ";
        sum += *it;
    }
    cout << endl;
    
    // TO-DO: Calculate the average of the sales values and print it
    //
    //
    
    cout << "Avg is: " << sum/dailySales.size() << endl;
    

    // TO-DO: Sort the vector in ascending order using std::sort.
    //
    sort(dailySales.begin(), dailySales.end()); // benridesu!!

    
    // TO-DO: Print all the sorted sales values by using an iterator
    //
    //
    
    for (it = dailySales.begin(); it != dailySales.end(); ++it) {
        cout << *it << " ";
//        sum += *it;
    }
    cout << endl;
    
    return 0;
}
