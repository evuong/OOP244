// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_in_lab.cpp
// Version: 2.0
// Date: November 15, 2018
// Author: Edward Vuong
// Description:
// This file tests in_lab section of your workshop
///////////////////////////////////////////////////

#ifndef SavingsAccount_h
#define SavingsAccount_h

#include <iostream>
#include "Account.h"

namespace sict {
    //derived class from Account class
    class SavingsAccount : public Account {
        double interest;
    public:
        SavingsAccount(double, double);
        void monthEnd();
        void display(std::ostream&) const;
    };
}
#endif
