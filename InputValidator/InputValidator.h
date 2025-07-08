//
// Created by Rashwan's on 08/07/2025.
//

#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

#include <string>
using namespace std;

namespace InputValidator {
    string getNonEmptyString();
    int getValidatedInt(int min, int max);
    double getValidatedDouble(double min);
}

#endif