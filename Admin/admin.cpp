//
// Created by Rashwan's on 08/07/2025.
//

#include "admin.h"
#include "../Books/PaperBook.h"
#include "../Books/EBook.h"
#include "../Books/DemoBook.h"
#include "../InputValidator/InputValidator.h"
#include <fstream>
#include <iostream>

using namespace std;

namespace AdminSession {

    vector<unique_ptr<book>> inventory;

    void loadInventory() {
        inventory.clear();
        ifstream file("../Data/book.txt");
        if (!file) return;

        string type;
        while (std::getline(static_cast<std::istream&>(file), type)) {
            unique_ptr<book> b;
            if (type == "PaperBook") {
                b = PaperBook::loadFromFile(file);
            } else if (type == "EBook") {
                b = EBook::loadFromFile(file);
            } else if (type == "DemoBook") {
                b = demobook::loadFromFile(file);
            }
            if (b) {
                inventory.push_back(move(b));
            }
        }
    }

    void saveInventory() {
        ofstream file("../Data/book.txt");
        for (const auto& b : inventory) {
            if (dynamic_cast<PaperBook*>(b.get())) file << "PaperBook\n";
            else if (dynamic_cast<EBook*>(b.get())) file << "EBook\n";
            else if (dynamic_cast<demobook*>(b.get())) file << "DemoBook\n";
            b->saveToFile(file);
        }
    }

    void viewInventory() {
        loadInventory(); // Ensure inventory is up-to-date from file
        cout << "\n===== Book Inventory =====\n";
        for (size_t i = 0; i < inventory.size(); ++i) {
            cout << "[" << i + 1 << "] ";
            inventory[i]->printDetails();
            cout << '\n';
        }
    }

    void addBook() {
        cout << "Select book type:\n1. PaperBook\n2. EBook\n3. DemoBook\nChoice: ";
        int choice = InputValidator::getValidatedInt(1, 3);
        string title, isbn;
        int year;
        double price;
        cout << "Enter title: ";
        title = InputValidator::getNonEmptyString();
        cout << "Enter year: ";
        year = InputValidator::getValidatedInt(1000, 2100);
        cout << "Enter price: ";
        price = InputValidator::getValidatedDouble(0.0);
        cout << "Enter ISBN: ";
        isbn = InputValidator::getNonEmptyString();

        if (choice == 1) {
            cout << "Enter stock: ";
            int stock = InputValidator::getValidatedInt(0, 1000);
            inventory.push_back(make_unique<PaperBook>(title, year, price, isbn, stock));
        } else if (choice == 2) {
            inventory.push_back(make_unique<EBook>(title, year, price, isbn));
        } else {
            inventory.push_back(make_unique<demobook>(title, year, price, isbn));
        }

        saveInventory(); // Save after adding
        cout << "Book added successfully.\n";
    }

    void removeBook() {
        viewInventory();
        cout << "Enter number of book to remove: ";
        int index = InputValidator::getValidatedInt(1, inventory.size()) - 1;
        inventory.erase(inventory.begin() + index);
        saveInventory(); // Save after removing
        cout << "Book removed.\n";
    }

    vector<unique_ptr<book>>& getInventory() {
        return inventory;
    }

    void adminMenu() {
        while (true) {
            cout << "\n=== Admin Menu ===\n";
            cout << "1. View Inventory\n";
            cout << "2. Add Book\n";
            cout << "3. Remove Book\n";
            cout << "4. Save and Exit\n";
            cout << "Enter choice: ";

            int choice = InputValidator::getValidatedInt(1, 4);

            switch (choice) {
                case 1:
                    viewInventory();
                    break;
                case 2:
                    addBook();
                    break;
                case 3:
                    removeBook();
                    break;
                case 4:
                    saveInventory();
                    cout << "Exiting admin session.\n";
                    return;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        }
    }
}