//
// Created by Rashwan's on 08/07/2025.
//

#include "book.h"


book::book(const string& title, int year, double price, const string& isbn)
    : title(title), year(year), price(price), isbn(isbn) {}

string book::getTitle() const { return title; }
int book::getYear() const { return year; }
double book::getPrice() const { return price; }
string book::getISBN() const { return isbn; }

void book::setPrice(double newPrice) {
    if (newPrice >= 0) {
        price = newPrice;
    }
}