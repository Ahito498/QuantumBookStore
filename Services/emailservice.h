//
// Created by Rashwan's on 08/07/2025.
//

#ifndef EMAILSERVICE_H
#define EMAILSERVICE_H

#include <vector>
#include <string>
#include "../Books/ebook.h"

using namespace std;

class emailservice {
private:
    static vector<string> sentBooks;

public:
    static void send(const vector<const EBook*>& books, const string& email);
    static void viewEmailLog();
};

#endif