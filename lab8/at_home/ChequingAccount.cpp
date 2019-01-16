// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_in_lab.cpp
// Version: 2.0
// Date: November 15, 2018
// Author: Edward Vuong
// Description:
// This file tests in_lab section of your workshop
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
    //sending initial balance off to Account constructor
    ChequingAccount::ChequingAccount (double initial, double trans, double end) : Account::Account(initial) {
        //checking both transaction fee and end of month fee individually
        if (trans > 0) {
            trans_fee = trans;
        }
        else {
            trans_fee = 0.0;
        }
        
        if (end > 0) {
            end_fee = end;
        }
        else {
            end_fee = 0.0;
        }
    }
    
    bool ChequingAccount::credit(double add) {
        if (Account::credit(add)) {         //if true do it and then minus transaction fee
            Account::debit(trans_fee);
            return true;
        }
        return false;
    }
    
    bool ChequingAccount::debit(double minus) {
        if (Account::debit(minus)) {        //if true do it and then minus transaction fee
            Account::debit(trans_fee);
            return true;
        }
        return false;
    }
    
    void ChequingAccount::monthEnd() {
        Account::debit(end_fee);
    }
    
    void ChequingAccount::display(std::ostream& output) const  {
        output << "Account type: Chequing" << endl;
        //setting to 2 decimal places
        output.setf(output.fixed, output.floatfield);
        output.precision(2);
        output << "Balance: $" << Account::balance() << endl;
        output << "Per Transaction Fee: " << trans_fee << endl;
        output << "Monthly Fee: " << end_fee << endl;
    }
    
}
