//
// Created by Rashwan's on 08/07/2025.
//

#include "emailservice.h"
#include <iostream>
using namespace std;

vector<string> emailservice::sentBooks;

void emailservice::send(const vector<const EBook*>& books, const string& email) {
    cout << "\n[EmailService] Sending the following e-books to: " << email << endl;

    for (size_t i = 0; i < books.size(); ++i) {
        const EBook* book = books[i];
        cout << "- " << book->getTitle() << endl;
        sentBooks.push_back(book->getTitle());
    }
}

void emailservice::viewEmailLog() {
    cout << "\n[Email Log]" << endl;

    if (sentBooks.empty()) {
        cout << "No e-books have been sent yet." << endl;
    } else {
        for (size_t i = 0; i < sentBooks.size(); ++i) {
            cout << "- " << sentBooks[i] << endl;
        }
    }
}