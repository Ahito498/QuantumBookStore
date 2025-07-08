//
// Created by Rashwan's on 08/07/2025.
//

#ifndef PAPERBOOK_H
#define PAPERBOOK_H

#include "book.h"
using namespace std;

class PaperBook : public book {
private:
    int stock;

public:
    PaperBook(const string& title, int year, double price, const string& isbn, int stock);

    bool isPurchasable() const override;
    bool isShippable() const override;
    bool isDigital() const override;

    void saveToFile(std::ofstream &out) const;

    void deliver(const string& address) const override;
    void printDetails() const override;

    int getStock() const;
    void decreaseStock(int qty) override;
    void setStock(int qty);

    static unique_ptr<book> loadFromFile(std::ifstream& in);
};

#endif