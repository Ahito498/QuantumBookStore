//
// Created by Rashwan's on 08/07/2025.
//

#include "demobook.h"

#include <fstream>
#include <iostream>

using namespace std;

demobook::demobook(const string& title, int year, double price, const string& isbn)
    : book(title, year, price, isbn) {}

bool demobook::isPurchasable() const {
    return false;
}

bool demobook::isShippable() const {
    return false;
}

bool demobook::isDigital() const {
    return false;
}

void demobook::deliver(const string& contact) const {
    cout << "Demo Book \"" << title << "\" is not for delivery." << endl;
}

void demobook::printDetails() const {
    cout << "[Demo Book] " << title
         << " | Year: " << year
         << " | Price: " << price
         << " | ISBN: " << isbn << " | Not For Sale" << endl;
}
unique_ptr<book> demobook::loadFromFile(std::ifstream& in) {
    string title, isbn;
    int year;
    double price;
    getline(in, title);
    in >> year >> price;
    in.ignore();
    getline(in, isbn);
    return make_unique<demobook>(title, year, price, isbn);
}

void demobook::saveToFile(std::ofstream& out) const {
    out << title << '\n' << year << '\n' << price << '\n' << isbn << '\n';
}