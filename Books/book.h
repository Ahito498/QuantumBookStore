//
// Created by Rashwan's on 08/07/2025.
//

#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class book {
protected:
    string title;
    int year;
    double price;
    string isbn;

public:
    book(const string& title, int year, double price, const string& isbn);
    virtual ~book() = default;

    string getTitle() const;
    int getYear() const;
    double getPrice() const;
    string getISBN() const;
    ///////////////
    virtual void setPrice(double newPrice); // only one setter for the price as it is the only charachterstic that AdminSession can update
    /////////////
    virtual bool isPurchasable() const = 0;
    virtual bool isShippable() const = 0;
    virtual bool isDigital() const = 0;
    ////////////
    virtual void deliver(const string& contact) const = 0;
    virtual void printDetails() const = 0;
    virtual void saveToFile(std::ofstream& out) const = 0;
    virtual void decreaseStock(int quantity) {}

    int getStock();
};

#endif