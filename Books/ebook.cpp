//
// Created by Rashwan's on 08/07/2025.
//
#include "ebook.h"

#include <fstream>
#include <iostream>

using namespace std;

EBook::EBook(const string& title, int year, double price, const string& isbn)
    : book(title, year, price, isbn) {}

bool EBook::isPurchasable() const {
    return true;
}

bool EBook::isShippable() const {
    return false;
}

bool EBook::isDigital() const {
    return true;
}

void EBook::deliver(const string& email) const {
    cout << "Sending E-Book \"" << title << "\" to email: " << email << endl;
}

void EBook::printDetails() const {
    cout << "[E-Book] " << title
         << " | Year: " << year
         << " | Price: " << price
         << " | ISBN: " << isbn << endl;
}
unique_ptr<book> EBook::loadFromFile(std::ifstream& in) {
    string title, isbn;
    int year;
    double price;
    getline(in, title);
    in >> year >> price;
    in.ignore();
    getline(in, isbn);
    return std::make_unique<EBook>(title, year, price, isbn);
}

void EBook::saveToFile(std::ofstream& out) const {
    out << title << '\n' << year << '\n' << price << '\n' << isbn << '\n';
}