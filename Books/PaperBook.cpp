//
// Created by Rashwan's on 08/07/2025.
//

#include "PaperBook.h"

#include <fstream>
#include <iostream>

using namespace std;

PaperBook::PaperBook(const string& title, int year, double price, const string& isbn, int stock)
    : book(title, year, price, isbn), stock(stock) {}

bool PaperBook::isPurchasable() const {
    return true;
}

bool PaperBook::isShippable() const {
    return true;
}

bool PaperBook::isDigital() const {
    return false;
}
void PaperBook::saveToFile(std::ofstream& out) const {
    out << title << '\n' << year << '\n' << price << '\n' << isbn << '\n' << stock << '\n';
}
void PaperBook::deliver(const string& address) const {
    cout << "Shipping Paper Book \"" << title << "\" to: " << address << endl;
}

void PaperBook::printDetails() const {
    cout << "[Paper Book] " << title
         << " | Year: " << year
         << " | Price: " << price
         << " | ISBN: " << isbn
         << " | Stock: " << stock << endl;
}

int PaperBook::getStock() const {
    return stock;
}

void PaperBook::decreaseStock(int qty) {
    stock -= qty;
}

void PaperBook::setStock(int qty) {
    stock = qty;
}

unique_ptr<book> PaperBook::loadFromFile(ifstream& in) {
    string title, isbn;
    int year, stock;
    double price;
    getline(in, title);
    in >> year >> price;
    in.ignore();
    getline(in, isbn);
    in >> stock;
    in.ignore();
    return make_unique<PaperBook>(title, year, price, isbn, stock);
}