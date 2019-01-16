// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_in_lab.cpp
// Version: 2.0
// Date: November 15, 2018
// Author: Edward Vuong
// Description:
// This file tests in_lab section of your workshop
///////////////////////////////////////////////////

#include "SavingsAccount.h"

using namespace std;

namespace sict {
    //sends balance to Account constructor and this constructor deals with the interest
    SavingsAccount::SavingsAccount(double bal, double newInterest) : Account::Account (bal) {
        if (newInterest > 0) {
            interest = newInterest;
        }
        else {
            interest = 0;
        }
    }
    
    void SavingsAccount::monthEnd() {
        double tbd = Account::balance()*interest;       //using balance function * interest to find tbd number
        Account::credit(tbd);                           //using credit function to add to account balance
    }
    
    void SavingsAccount::display(std::ostream& output) const  {
        output << "Account type: Savings" << endl;
        //setting to 2 decimal places
        output.setf(output.fixed, output.floatfield);
        output.precision(2);
        output << "Balance: $" << Account::balance() << endl;
        output << "Interest Rate (%): " << interest*100 << endl;        //*100 to display it properly
    }
}
