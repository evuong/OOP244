// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_in_lab.cpp
// Version: 2.0
// Date: November 15, 2018
// Author: Edward Vuong
// Description:
// This file tests in_lab section of your workshop
///////////////////////////////////////////////////

#include "Account.h"
using namespace std;

namespace sict {
    Account::Account(double bal) {
        if (bal > 0) {
            current = bal;
        }
        else {
            current = 0.0;
        }
    }
    
    bool Account::credit(double add) {
        if (add > 0) {
            current += add;
            return true;
        }
        return false;
    }
    
    bool Account::debit(double minus) {
        if (minus > 0) {
            current -= minus;
            return true;
        }
        return false;
    }
    
    double Account::balance() const {
        return current;
    }
}
