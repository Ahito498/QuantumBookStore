//
// Created by Rashwan's on 08/07/2025.
//

#ifndef CARTITEM_H
#define CARTITEM_H

#include "../Books/book.h"

class cartitem {
private:
    const book* item;
    int quantity;

public:
    cartitem(const book* item, int quantity);

    const book* getItem() const;
    int getQuantity() const;
    void setQuantity(int quantity);
};

#endif