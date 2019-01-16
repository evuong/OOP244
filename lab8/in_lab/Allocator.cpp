// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_in_lab.cpp
// Version: 2.0
// Date: November 15, 2018
// Author: Edward Vuong
// Description:
// This file tests in_lab section of your workshop
///////////////////////////////////////////////////

#include <iostream>
#include "SavingsAccount.h"
using namespace std;

namespace sict {
    const double interest = 0.05;
    
    iAccount* CreateAccount (const char* type, double bal) {
        iAccount* open;
        if (type[0] == 'S' || type[0] == 's') {
            open = new SavingsAccount(bal, interest);
            return open;
        }
        return open=nullptr;
    }
    
    
}
