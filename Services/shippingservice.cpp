//
// Created by Rashwan's on 08/07/2025.
//

#include "shippingservice.h"
#include <iostream>
using namespace std;

vector<string> shippingservice::shippedBooks;

void shippingservice::ship(const vector<const PaperBook*>& books, const string& address) {
    cout << "\n[ShippingService] Shipping the following books to: " << address << endl;

    for (size_t i = 0; i < books.size(); ++i) {
        const PaperBook* book = books[i];
        cout << "- " << book->getTitle() << endl;
        shippedBooks.push_back(book->getTitle());
    }
}

void shippingservice::viewShippingLog() {
    cout << "\n[Shipping Log]" << endl;

    if (shippedBooks.empty()) {
        cout << "No books have been shipped yet." << endl;
    } else {
        for (size_t i = 0; i < shippedBooks.size(); ++i) {
            cout << "- " << shippedBooks[i] << endl;
        }
    }
}