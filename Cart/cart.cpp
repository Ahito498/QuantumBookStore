//
// Created by Rashwan's on 08/07/2025.
//

#include "cart.h"
#include <iostream>
#include "../books/paperbook.h"
using namespace std;

void cart::addItem(const book* b, int quantity) {
    items.push_back(cartitem(b, quantity));
}

void cart::removeItem(int index) {
    if (index >= 0 && index < static_cast<int>(items.size())) {
        items.erase(items.begin() + index);
    }
}

void cart::viewCart() const {
    if (items.empty()) {
        cout << "Cart is empty." << endl;
        return;
    }

    cout << "\n----- Your Cart -----" << endl;
    for (size_t i = 0; i < items.size(); ++i) {
        const book* b = items[i].getItem();

        // Dynamic cast to check if it's a PaperBook
        const PaperBook* pb = dynamic_cast<const PaperBook*>(b);
        string note = (pb != nullptr) ? " (Physical Copy)" : " (Digital Copy)";

        cout << "[" << i + 1 << "] " << b->getTitle()
             << note
             << " | Quantity: " << items[i].getQuantity()
             << " | Subtotal: " << items[i].getQuantity() * b->getPrice()
             << endl;
    }
}

double cart::calculateSubtotal() const {
    double total = 0;
    for (size_t i = 0; i < items.size(); ++i) {
        total += items[i].getQuantity() * items[i].getItem()->getPrice();
    }
    return total;
}

bool cart::isEmpty() const {
    return items.empty();
}

const vector<cartitem>& cart::getItems() const {
    return items;
}

void cart::clear() {
    items.clear();
}