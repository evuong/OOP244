// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_in_lab.cpp
// Version: 2.0
// Date: November 15, 2018
// Author: Edward Vuong
// Description:
// This file tests in_lab section of your workshop
///////////////////////////////////////////////////

#ifndef Account_h
#define Account_h

#include <iostream>
#include "iAccount.h"

namespace sict {
    //derived class from iAccount class
    class Account : public iAccount {
        double current;
    public:
        Account (double);
        bool credit (double);
        bool debit (double);
    protected:
        double balance() const;
    };
}

#endif
