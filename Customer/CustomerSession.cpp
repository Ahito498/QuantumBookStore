#include "CustomerSession.h"

#include <fstream>

#include "../Books/demobook.h"

using namespace std;

namespace CustomerSession {

    vector<Customer> customers;
    cart cart;
    Customer* loggedInCustomer = nullptr;

    void loadCustomers() {
        customers.clear();
        ifstream file("../Data/customers.txt");
        string username;
        double balance;
        while (file >> username >> balance) {
            customers.emplace_back(username, "", "", balance);
        }
    }

    void saveCustomers() {
        std::ofstream file("Data/customers.txt");
        for (size_t i = 0; i < customers.size(); ++i) {
            file << customers[i].getUsername() << ' ' << customers[i].getBalance() << '\n';
        }
    }

    void login() {
        cout << "Enter username: ";
        string username = InputValidator::getNonEmptyString();
        for (size_t i = 0; i < customers.size(); ++i) {
            if (customers[i].getUsername() == username) {
                loggedInCustomer = &customers[i];
                cout << "Login successful.\n";
                return;
            }
        }
        cout << "Login failed.\n";
    }

    void signUp() {
        cout << "Enter a new username: ";
        string username = InputValidator::getNonEmptyString();
        for (size_t i = 0; i < customers.size(); ++i) {
            if (customers[i].getUsername() == username) {
                cout << "Username already exists.\n";
                return;
            }
        }
        cout << "Enter email: ";
        string email = InputValidator::getNonEmptyString();
        cout << "Enter address: ";
        string address = InputValidator::getNonEmptyString();
        cout << "Enter starting balance: ";
        double balance = InputValidator::getValidatedDouble(0);
        customers.emplace_back(username, email, address, balance);
        saveCustomers();
        cout << "Account created successfully.\n";
    }

    void viewBooks() {
        AdminSession::viewInventory();
    }

    void addToCart() {
        AdminSession::viewInventory();
        cout << "Enter book number to add: ";
        int index = InputValidator::getValidatedInt(1, AdminSession::getInventory().size()) - 1;
        book* selected = AdminSession::getInventory()[index].get();
        if (selected->isPurchasable()) {
            cout << "Enter quantity: ";
            int qty = InputValidator::getValidatedInt(1, selected->getStock());
            cart.addItem(selected, qty);
            cout << "Book added to cart.\n";
        } else {
            cout << "This book is not available for purchase.\n";
        }
    }

    void viewCart() {
        cart.viewCart();
    }

    void removeFromCart() {
        viewCart();
        cout << "Enter item number to remove: ";
        int index = InputValidator::getValidatedInt(1, cart.getItems().size()) - 1;
        cart.removeItem(index);
        cout << "Item removed from cart.\n";
    }

    void checkout() {
        if (cart.isEmpty()) {
            cout << "Cart is empty.\n";
            return;
        }

        double total = 0.0;
        std::vector<book*> emailBooks;
        std::vector<book*> shippedBooks;

        const auto& items = cart.getItems();
        for (size_t i = 0; i < items.size(); ++i) {
            book* b = const_cast<book*>(items[i].getItem());
            int qty = items[i].getQuantity();
            total += qty * b->getPrice();

            if (auto* pb = dynamic_cast<PaperBook*>(b)) {
                if (qty > pb->getStock()) {
                    cout << "Only " << pb->getStock() << " copies of \"" << pb->getTitle() << "\" are available.\n";
                    return;
                }
                pb->decreaseStock(qty);
                shippedBooks.push_back(pb);
            } else if (auto* eb = dynamic_cast<EBook*>(b)) {
                emailBooks.push_back(eb);
            } else if (dynamic_cast<demobook*>(b)) {
                cout << "Demo book \"" << b->getTitle() << "\" is not available for purchase.\n";
                return;
            }
        }

        if (loggedInCustomer->getBalance() < total) {
            cout << "Insufficient balance.\n";
            return;
        }

        loggedInCustomer->deduct(total);

        if (!shippedBooks.empty()) {
            cout << "Enter your shipping address: ";
            string address = InputValidator::getNonEmptyString();
            std::vector<const PaperBook*> paperBooks;
            for (auto* b : shippedBooks) {
                if (auto* pb = dynamic_cast<const PaperBook*>(b)) {
                    paperBooks.push_back(pb);
                }
            }
            shippingservice::ship(paperBooks, address);
        }

        if (!emailBooks.empty()) {
            string email = loggedInCustomer->getEmail();
            std::vector<const EBook*> ebooks;
            for (auto* b : emailBooks) {
                if (auto* eb = dynamic_cast<const EBook*>(b)) {
                    ebooks.push_back(eb);
                }
            }
            emailservice::send(ebooks, email);
        }

        cart.clear();
        cout << "Checkout complete. Paid: $" << total << '\n';
    }

    void customerMenu() {
        int choice;
        do {
            cout << "\n1. View Books\n2. Add to Cart\n3. View Cart\n4. Remove from Cart\n5. Checkout\n0. Logout\nChoice: ";
            choice = InputValidator::getValidatedInt(0, 5);
            switch (choice) {
                case 1: viewBooks(); break;
                case 2: addToCart(); break;
                case 3: viewCart(); break;
                case 4: removeFromCart(); break;
                case 5: checkout(); break;
            }
        } while (choice != 0);
        loggedInCustomer = nullptr;
        cart.clear();
        cout << "Logged out.\n";
    }

} // namespace