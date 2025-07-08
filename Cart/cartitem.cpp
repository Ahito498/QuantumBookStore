//
// Created by Rashwan's on 08/07/2025.
//
#include "cartitem.h"

cartitem::cartitem(const book* item, int quantity) : item(item), quantity(quantity) {}

const book* cartitem::getItem() const {
    return item;
}

int cartitem::getQuantity() const {
    return quantity;
}

void cartitem::setQuantity(int qty) {
    quantity = qty;
}

