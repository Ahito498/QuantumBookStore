//
// Created by Rashwan's on 08/07/2025.
//

#include "customer.h"

Customer::Customer(const std::string& username, const std::string& email, const std::string& address, double balance)
    : username(username), email(email), address(address), balance(balance) {}

const std::string& Customer::getUsername() const {
    return username;
}

const std::string& Customer::getEmail() const {
    return email;
}

const std::string& Customer::getAddress() const {
    return address;
}

double Customer::getBalance() const {
    return balance;
}

void Customer::deduct(double amount) {
    balance -= amount;
}

void Customer::addBalance(double amount) {
    balance += amount;
}