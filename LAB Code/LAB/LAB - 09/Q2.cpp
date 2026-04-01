//
//  Q2.cpp
//  LAB
//
//  Created by 邹嘉睿 on 2026.03.31.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Product {
private:
    string name;
    double price;

public:
    // Constructor
    Product(string productName, double productPrice) {
        //TO-DO: Write Your Code Here
        //
        //
        if(productPrice > 0){
            name = productName;
            price = productPrice;
        }else{
            cout << "Error: Price cannot be negative!" << endl;
        }
        return;
    }

    // Destructor
    //TO-DO: Write Your Code Here
    //
    //
    ~Product() = default;

    // Getters
    //TO-DO: Write Your Code Here
    //
    //
    string getName(){
        return name;
    }

    double getPrice(){
        return price;
    }

    // Setter for price (ensures non-negative value)
    void setPrice(double newPrice) {
        //TO-DO: Write Your Code Here
        //
        //
        if(newPrice > 0){
            price = newPrice;
        }else{
            cout << "Error: Price cannot be negative!" << endl;
        }
    }
};
int main() {
    vector<Product> products;

    cout << "1) Create new product" << endl;
    cout << "2) Print Product" << endl;
    cout << "3) Update Price" << endl;
    cout << "4) Exit" << endl;

    int cmd;
    do {
        cout << "Enter command: " << endl;
        cin >> cmd;
        switch(cmd) {
        case 1:
            {
                cout << "Enter product name and price:" << endl;
                string name;
                double price;
                cin >> name >> price;
                products.emplace_back(Product(name, price));
                cout << "Product created: " << name << " ($" << price << ")" << endl;
            }
            break;
        case 2:
            {
                cout << "Enter product id:" << endl;
                size_t index;
                cin >> index;
                if (index >= products.size()) {
                    cout << "Selected index " << index << " is out of bounds" << endl;
                    break;
                }

                cout << "The name of Product " << index << ": " << products[index].getName() << endl;
                cout << "The price of Product " << index << ": $" << products[index].getPrice() << endl;
            }
            break;
        case 3:
            {
                cout << "Enter product id and new price:" << endl;
                size_t index;
                double price;
                cin >> index >> price;
                if (index >= products.size()) {
                    cout << "Selected index " << index << " is out of bounds" << endl;
                    break;
                }

                products[index].setPrice(price);
            }
            break;
        case 4:
            break;
        default:
            cout << "Unknown cmd: " << cmd << endl;
        }
    } while (cmd != 4);

    return 0;
}
