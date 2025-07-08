//
// Created by Rashwan's on 08/07/2025.
//

#ifndef DEMOBOOK_H
#define DEMOBOOK_H

#include "book.h"
using namespace std;

class demobook : public book {
public:
    demobook(const string& title, int year, double price, const string& isbn);

    bool isPurchasable() const override;
    bool isShippable() const override;
    bool isDigital() const override;

    void deliver(const string& contact) const override;
    void printDetails() const override;


    static unique_ptr<book> loadFromFile(std::ifstream& in);
    void saveToFile(std::ofstream& out) const override;
};

#endif