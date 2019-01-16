/////////////////////////////////////////////////////////////////
// Final Project - Milestone 5
// November 28, 2018
// Edward Vuong
// 120246186
/////////////////////////////////////////////////////////////////

#include "Perishable.h"
#include <iostream>
using namespace std;

namespace aid {
    
    Perishable::Perishable() : Good('P'){ //nothing
    }
    
    std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
        Good::store(file, false);     //calls base class and passes fstream file and false
        file << ",";
        exp.write(file);
        if (newLine) {
            file << endl;
        }
        return file;
    }
    
    std::fstream& Perishable::load(std::fstream& file) {
        Good::load(file);
        exp.read(file);
        file.ignore();
        return file;
    }
    
    std::ostream& Perishable::write(std::ostream& os, bool linear) const {
        Good::write(os, linear);
        if (isClear() && !isEmpty()) {
            if (linear) {
                exp.write(os);
            }
            else {
                os << endl << " Expiry date: ";
                exp.write(os);
            }
        }
        return os;
    }
    
    std::istream& Perishable::read(std::istream& is) {
        is.clear();
        Good::read(is);
        
        if (state.isClear()) {
            cout << " Expiry date (YYYY/MM/DD): ";
            exp.read(is);
        }
        
        //checks for all the potential errors with the expiry date entered
        if (exp.errCode() == CIN_FAILED) {
            state.clear();
            state.message("Invalid Expiry in Date Entry");
            is.setstate(ios::failbit);
        }
        
        if (exp.errCode() == YEAR_ERROR) {
            state.message("Invalid Year in Date Entry");
            is.setstate(ios::failbit);
        }

        if (exp.errCode() == MON_ERROR) {
            state.clear();
            state.message("Invalid Month in Date Entry");
            is.setstate(ios::failbit);
        }
        
        if (exp.errCode() == DAY_ERROR) {
            state.clear();
            state.message("Invalid Day in Date Entry");
            is.setstate(ios::failbit);
        }
        
        if (exp.errCode() == PAST_ERROR) {
            state.clear();
            state.message("Invalid Expiry in Date Entry");
            is.setstate(ios::failbit);
        }

        if (exp.errCode() == NO_ERROR) {
            state.clear();
        }
        return is;
    }
    
    const Date& Perishable::expiry() const {
        return exp;
    }
}
