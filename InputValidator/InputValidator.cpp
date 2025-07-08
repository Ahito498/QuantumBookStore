//
// Created by Rashwan's on 08/07/2025.
//

#include "InputValidator.h"
#include <iostream>
#include <limits>

using namespace std;

namespace InputValidator {

    string getNonEmptyString() {
        string input;
        do {
            getline(cin, input);
            if (input.empty()) {
                cout << "Input cannot be empty. Try again: ";
            }
        } while (input.empty());
        return input;
    }

    int getValidatedInt(int min, int max) {
        int value;
        while (true) {
            cin >> value;
            if (cin.fail() || value < min || value > max) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Enter an integer between " << min << " and " << max << ": ";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
        }
    }

    double getValidatedDouble(double min) {
        double value;
        while (true) {
            cin >> value;
            if (cin.fail() || value < min) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Enter a value >= " << min << ": ";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
        }
    }

}