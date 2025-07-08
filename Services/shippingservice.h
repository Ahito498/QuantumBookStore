//
// Created by Rashwan's on 08/07/2025.
//

#ifndef SHIPPING_SERVICE_H
#define SHIPPING_SERVICE_H

#include <vector>
#include <string>
#include "../Books/PaperBook.h"

using namespace std;

class shippingservice {
private:
    static vector<string> shippedBooks;

public:
    static void ship(const vector<const PaperBook*>& books, const string& address);
    static void viewShippingLog();
};

#endif
