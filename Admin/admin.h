//
// Created by Rashwan's on 08/07/2025.
//


#ifndef ADMINSESSION_H
#define ADMINSESSION_H

#include <vector>
#include <memory>
#include "../Books/book.h"

namespace AdminSession {
    void loadInventory();
    void saveInventory();
    void viewInventory();
    void addBook();
    void adminMenu();
    void removeBook();
    std::vector<std::unique_ptr<book>>& getInventory();
}

#endif // ADMINSESSION_H