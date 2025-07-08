//
// Created by Rashwan's on 08/07/2025.
//


#ifndef CART_H
#define CART_H

#include "cartitem.h"
#include <vector>
using namespace std;

class cart {
private:
    vector<cartitem> items;

public:
    void addItem(const book* b, int quantity);
    void removeItem(int index);
    void viewCart() const;
    double calculateSubtotal() const;
    bool isEmpty() const;
    const vector<cartitem>& getItems() const;
    void clear();
};

#endif