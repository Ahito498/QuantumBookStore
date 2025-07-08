#include "Admin/admin.h"
#include "Customer/CustomerSession.h"
#include "..//QuantumBookStore/InputValidator/InputValidator.h"
#include <iostream>
//#include "..//QuantumBookStore/Test/BookInventoryTest.h"

using namespace std;

int main() {
    int choice;
    do {
        cout << "\n===== Quantum Book Store =====" << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. Customer Login" << endl;
        cout << "3. Customer Sign Up" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";

        choice = InputValidator::getValidatedInt(0, 3);

        switch (choice) {
            case 1:
                AdminSession::adminMenu();
            break;
            case 2:
                CustomerSession::loadCustomers();
            CustomerSession::login();
            CustomerSession::customerMenu();
            break;
            case 3:
                CustomerSession::loadCustomers();
            CustomerSession::signUp();
            break;
            case 0:
                cout << "Exiting application. Goodbye!" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}