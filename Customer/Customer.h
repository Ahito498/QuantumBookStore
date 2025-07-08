//
// Created by Rashwan's on 08/07/2025.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string username;
    std::string email;
    std::string address;
    double balance;

public:
    Customer() = default;
    Customer(const std::string& username, const std::string& email, const std::string& address, double balance);

    const std::string& getUsername() const;
    const std::string& getEmail() const;
    const std::string& getAddress() const;
    double getBalance() const;

    void deduct(double amount);
    void addBalance(double amount);
};

#endif
