//
// Created by Rashwan's on 08/07/2025.
//

#ifndef CUSTOMER_SESSION_H
#define CUSTOMER_SESSION_H

#include "../Customer/Customer.h"
#include "../Cart/cart.h"
#include "../InputValidator/InputValidator.h"
#include "../Books/book.h"
#include "../Admin/admin.h"
#include "../Services/shippingservice.h"
#include "../Services/emailservice.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace CustomerSession {

    extern vector<Customer> customers;
    extern cart customerCart;
    extern Customer* loggedInCustomer;

    void loadCustomers();
    void saveCustomers();

    void signUp();
    void login();

    void customerMenu();

    void viewBooks();
    void addToCart();
    void viewCart();
    void removeFromCart();
    void checkout();

}

#endif // CUSTOMER_SESSION_H