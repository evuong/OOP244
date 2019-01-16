// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_in_lab.cpp
// Version: 2.0
// Date: November 15, 2018
// Author: Edward Vuong
// Description:
// This file tests in_lab section of your workshop
///////////////////////////////////////////////////

#ifndef ChequingAccount_h
#define ChequingAccount_h

#include <iostream>
#include "Account.h"

namespace sict {
    class ChequingAccount : public Account {
        double trans_fee;
        double end_fee;
    public:
        ChequingAccount(double, double, double);
        bool credit(double);
        bool debit(double);
        void monthEnd();
        void display(std::ostream&) const;
    };
    
}
#endif
