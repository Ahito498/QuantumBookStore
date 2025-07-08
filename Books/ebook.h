//
// Created by Rashwan's on 08/07/2025.
//

#ifndef EBOOK_H
#define EBOOK_H

#include "book.h"
using namespace std;

class EBook : public book {
public:
    EBook(const string& title, int year, double price, const string& isbn);

    bool isPurchasable() const override;
    bool isShippable() const override;
    bool isDigital() const override;

    void deliver(const string& email) const override;
    void printDetails() const override;

    static unique_ptr<book> loadFromFile(std::ifstream& in);
    void saveToFile(std::ofstream& out) const override;
};

#endif